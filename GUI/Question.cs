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
        public Question()
        {
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
                    buttonAnswer2.Text = msg.Substring(msg.IndexOf("2") + 1, msg.IndexOf("3"));
                    buttonAnswer3.Text = msg.Substring(msg.IndexOf("3") + 1, msg.IndexOf("4"));
                    buttonAnswer4.Text = msg.Substring(msg.IndexOf("4") + 1);
                }
            }
            else
            {
                MessageBox.Show("Failed communicating with server", "Server Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
