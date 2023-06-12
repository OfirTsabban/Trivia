using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GUI
{
    public partial class RoomInfo : Form
    {
        private int roomId;
        private string user;
        private bool hasGameBegun = false;
        public RoomInfo(int id, string userName)
        {
            this.user = userName;
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
                if (players.Contains(","))
                {
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
            }
            else
            {
                MessageBox.Show("Failed communicating with server", "Server Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void buttonStart_Click(object sender, EventArgs e)
        {
            if(this.user == this.LabelAdminName.Text)
            {
                if (Connector.sendMSG("Start Game", (int)Connector.Requests.Admin_Start_Game))
                {
                    this.hasGameBegun = true;
                }
                else
                {
                    MessageBox.Show("Failed communicating with server", "Server Error", MessageBoxButtons.OK, MessageBoxIcon.Error);                
                }
            }
            else
            {
                MessageBox.Show("Only host may start a game", "Warning", MessageBoxButtons.OKCancel);
            }
        }

        private void buttonRefresh_Click(object sender, EventArgs e)
        {
            //ignore
        }

        private void buttonLeave_Click(object sender, EventArgs e)
        {
            if(this.user == this.LabelAdminName.Text)
            {
                if(Connector.sendMSG("CloseRoom", (int)Connector.Requests.Close_Room))
                {
                    string msg = Connector.recvMSG();
                    //need to do more;
                }
                else
                {
                    MessageBox.Show("Failed communicating with server", "Server Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
            else
            {
                if (Connector.sendMSG("LeaveRoom", (int)Connector.Requests.Leave_Room))
                {
                    string msg = Connector.recvMSG();
                    //need to do more;
                }
                else
                {
                    MessageBox.Show("Failed communicating with server", "Server Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }

        private void buttonRoomState_Click(object sender, EventArgs e)
        {            
            if (Connector.sendMSG("GetRoomState", (int)Connector.Requests.Room_State))
            {
                string msg = Connector.recvMSG();
                msg = msg.Substring(msg.IndexOf(":") + 1);
                msg = msg.Substring(0, msg.IndexOf("}"));                
                MessageBox.Show(msg, "Room State", MessageBoxButtons.OK);                
            }
            else
            {
                MessageBox.Show("Failed communicating with server", "Server Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
