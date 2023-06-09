﻿using System;
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
                string response = Connector.recvMSG();//every player is seperated with ","
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
