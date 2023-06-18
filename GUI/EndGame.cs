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
    public partial class EndGame : Form
    {
        private string players;
        private string user;
        public EndGame(string players, string user)
        {
            this.user = user;
            this.players = players;
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void EndGame_Load(object sender, EventArgs e)
        {
            this.labelUserName.Text = this.user;
            string player = "";
            for (int i = 0; i < this.players.Length; i++)
            {
                if (this.players[i] == ',')
                {
                    this.listViewPlayers.Items.Add(player);
                    player = "";
                }
                else
                {
                    player += this.players[i];
                }
            }
            if(Connector.sendMSG("gameResult", (int)Connector.Requests.Get_Game_Result))
            {
                string msg = Connector.recvMSG();
                
                msg = msg.Substring(msg.IndexOf("avarage answer time: " + 21));
                this.labelTime.Text = msg.Substring(0, msg.IndexOf(","));
                msg = msg.Substring(msg.IndexOf("correct answer count: " + 22));
                this.labelCorrectAnswers.Text = msg.Substring(0, msg.IndexOf(","));
                this.labelName.Text =  msg.Substring(msg.IndexOf("winner: " + 8));
            }
            else
            {
                MessageBox.Show("Failed communicating with server", "Server Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void buttonBack_Click(object sender, EventArgs e)
        {
            Form1 mainMenu = new Form1(this.user);
            Hide();
            mainMenu.Show();
        }
    }
}
