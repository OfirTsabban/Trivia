using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Linq;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace GUI
{
    public partial class CreateRoom : Form
    {
        public CreateRoom()
        {
            InitializeComponent();
        }

        private void CreateRoom_Load(object sender, EventArgs e)
        {

        }

        private void buttonRoomInfo_Click(object sender, EventArgs e)
        {

        }

        private void buttonNext_Click(object sender, EventArgs e)
        {
            bool error = false;
            int fieldsFilled = 0, timePerQ = 0, playersNum = 0, questionsNum = 0;
            string roomName = textBoxRoomName.Text;
            if (chkRoomName(roomName) != "" && !error)
            {
                MessageBox.Show(chkRoomName(roomName));
                error = true;
            }
            else
            {
                fieldsFilled++;
            }
            if(cboTime.SelectedItem != null)
            {
                timePerQ = int.Parse(cboTime.SelectedItem.ToString());
                fieldsFilled++;
            }
            if (cboPlayersNum.SelectedItem != null)
            {
                playersNum = int.Parse(cboPlayersNum.SelectedItem.ToString());
                fieldsFilled++;
            }
            if (cboNumberQuestions.SelectedItem != null)
            {
                questionsNum = int.Parse(cboNumberQuestions.SelectedItem.ToString());
                fieldsFilled++;
            }
            
            if(fieldsFilled == 4)
            {
                string json = Protocol.createRoomRequestProtocol(roomName, playersNum, questionsNum, timePerQ);

                if (Connector.sendMSG(json, (int)Connector.Requests.Create_Room))
                {
                    if(Connector.statusFromServer())
                    {
                        Form1 mainMenu = new Form1();//need to change in 3.0.0
                        Hide();
                        mainMenu.Show();
                    }
                }
                else
                {
                    MessageBox.Show("Failed to send to server", "Server Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }

        }

        private void textBoxTime_TextChanged(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void cboPlayersNum_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void textBoxRoomName_TextChanged(object sender, EventArgs e)
        {

        }

        private string chkRoomName(string roomName)
        {
            if (roomName.Length < 2)
            {
                return "Error - room name is too short";
            }
            else if (roomName.Length > 30)
            {
                return "Error - room name is too long";
            }
            else if (containHebrew(roomName))
            {
                return "Error - room name cant contain Hebrew";
            }
            else if (badChar(roomName))
            {
                return "Error - room name cant contain special characters";
            }
            else if (isQuot(roomName))
            {
                return "Error - room name cant contain special quotes";
            }

            return "";
        }

        bool containHebrew(string name)
        {
            for (int i = 0; i < name.Length; i++)
            {
                if (name[i] >= 'א' && name[i] <= 'ת')
                {
                    return true;
                }
            }

            return false;
        }

        bool badChar(string name)
        {
            string badChars = "~!@#$%^&*()+=-/|[,?]{}";

            for (int i = 0; i < name.Length; i++)
            {
                if (badChars.Contains(Char.ToString(name[i])))
                {
                    return true;
                }
            }

            return false;
        }

        bool isQuot(string name)
        {
            char quot = '"'; string quot1 = "'";

            if (name.IndexOf(quot) != -1 || name.IndexOf(quot1) != -1)
                return true;
            return false;
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }
    }
}
