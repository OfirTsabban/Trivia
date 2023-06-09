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
    public partial class RoomInfo : Form
    {
        private int roomId;
        public RoomInfo(int id)
        {
            this.roomId = id;
            InitializeComponent();
        }

        private void LabelAdminName_Click(object sender, EventArgs e)
        {
            
        }

        private void listViewPlayers_SelectedIndexChanged(object sender, EventArgs e)
        {
           
        }

        private void RoomInfo_Load(object sender, EventArgs e)
        {
            string json = Protocol.getPlayersProtocol(this.roomId);
            if (Connector.sendMSG(json, (int)Connector.Requests.Get_Players))
            {
                string players = Connector.recvMSG();
                players = players.Substring(players.IndexOf(':') + 2); 
                string admin = players.Substring(0, players.IndexOf(','));
                players = players.Substring(players.IndexOf(',') + 1);
                string player = "";
                this.LabelAdminName.Text = admin;
                for (int i = 0; i < players.Length; i++)
                {
                    if (players[i] == ',')
                    {
                        this.listViewPlayers.Items.Add(player);
                        player = "";
                    }
                    else
                    {
                        player += players[i];
                    }
                }
            }
            else
            {
                MessageBox.Show("Failed communicating with server", "Server Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void buttonStart_Click(object sender, EventArgs e)
        {

        }

        private void buttonRefresh_Click(object sender, EventArgs e)
        {
            //ignore
        }
    }
}
