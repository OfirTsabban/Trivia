using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GUI
{
    public partial class Question : Form
    {        
        private int timePerQuestion;
        private int totalQuestions;
        private int questionCount;
        private int timeLeft;
        private int rightQuestionsNum;
        private string room;
        public Question(int timePerQuestions, int totalQuestions, string room)
        {
            this.room = room;
            this.rightQuestionsNum = 0;
            this.timePerQuestion = timePerQuestions;
            this.totalQuestions = totalQuestions;
            InitializeComponent();            
        }

        private void labelCorresctAnswer_Click(object sender, EventArgs e)
        {

        }

        private void Question_Load(object sender, EventArgs e)
        {
            this.labelRoomName.Text = this.room;
            this.labelCorresctAnswer.Text = this.rightQuestionsNum.ToString();
            this.labelQuestionsLeft.Text = (this.totalQuestions - this.questionCount).ToString();
            this.timeLeft = Convert.ToInt32(this.timePerQuestion);
            this.labelTime.Enabled = false;
            this.timer1.Start();
            if (Connector.sendMSG("GetQuestion", (int)Connector.Requests.Get_Question))
            {
                string msg = Connector.recvMSG();
                if(msg.Contains("question:"))
                {                    
                    this.labelQuestion.Text = msg.Substring(msg.IndexOf("question: ") + 10, msg.IndexOf(",")); ;
                    msg = msg.Substring(msg.IndexOf("1") + 1);
                    buttonAnswer1.Text = msg.Substring(0, msg.IndexOf("2"));
                    buttonAnswer2.Text = msg.Substring(msg.IndexOf("2") + 2, msg.IndexOf("3"));
                    buttonAnswer3.Text = msg.Substring(msg.IndexOf("3") + 2, msg.IndexOf("4"));
                    buttonAnswer4.Text = msg.Substring(msg.IndexOf("4") + 2);
                }
            }
            else
            {
                MessageBox.Show("Failed communicating with server", "Server Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }            
                              
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            this.labelTime.Text = (this.timeLeft--).ToString(); 
        }

        private void buttonAnswer1_Click(object sender, EventArgs e)
        {
            AnswerSubmited(1, sender, e);
        }
        
        private void buttonAnswer2_Click(object sender, EventArgs e)
        {
            AnswerSubmited(2, sender, e);
        }        

        private void buttonAnswer3_Click(object sender, EventArgs e)
        {
            AnswerSubmited(3, sender, e);
        }

        private void buttonAnswer4_Click(object sender, EventArgs e)
        {
            AnswerSubmited(4, sender, e);
        }

        private void AnswerSubmited(int id, object sender, EventArgs e)
        {
            this.timer1.Stop();
            this.timeLeft = this.timePerQuestion;
            if (Connector.sendMSG("submitAnswer", (int)Connector.Requests.Submit_Answer))
            {
                string msg = Connector.recvMSG();
                if (msg.Contains("correctAnswerId: "))
                {
                    string correctId = msg.Substring(msg.IndexOf("correctAnswerId: ") + 17);
                    if (id == int.Parse(correctId))
                    {
                        this.rightQuestionsNum++;
                    }
                    Question_Load(sender, e);
                }
            }
            else
            {
                MessageBox.Show("Failed communicating with server", "Server Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
