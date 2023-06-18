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
        public Question(int timePerQuestions, int totalQuestions)
        {
            this.timePerQuestion = timePerQuestions;
            this.totalQuestions = totalQuestions;
            InitializeComponent();
        }

        private void labelCorresctAnswer_Click(object sender, EventArgs e)
        {

        }

        private void Question_Load(object sender, EventArgs e)
        {
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
            this.labelQuestionsLeft.Text = (this.totalQuestions - this.questionCount).ToString();
            this.timeLeft = Convert.ToInt32(this.timePerQuestion);
            this.labelTime.Enabled = false;
            this.timer1.Start();                   
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            this.labelTime.Text = (this.timeLeft--).ToString(); 
        }

        private void buttonAnswer1_Click(object sender, EventArgs e)
        {
            
        }
    }
}
