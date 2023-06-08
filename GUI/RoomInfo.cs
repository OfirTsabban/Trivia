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
        public RoomInfo()
        {
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

        }

        private void buttonStart_Click(object sender, EventArgs e)
        {

        }

        private void buttonRefresh_Click(object sender, EventArgs e)
        {
            //if(Connector.sendMSG("getPlayers", (int)Connector.Requests.Get_Players))
            //{
            //    listViewPlayers.Items.Clear();
            //    string players = Connector.recvMSG();
            //    players = players.Substring(players.IndexOf("i"));
            //    string player = "";
            //    for (int i = 0; i < players.Length; i++)
            //    {
            //        if (players[i] == ',')
            //        {
            //            listViewPlayers.Items.Add(player);
            //            player = "";
            //        }
            //        else
            //        {
            //            player += players[i];
            //        }
            //    }
            //}
            //else
            //{
            //    MessageBox.Show("Failed communicating with server", "Server Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            //}
            //needs more work ill do it tmw
        }
    }
}
