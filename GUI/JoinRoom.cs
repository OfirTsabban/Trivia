using System;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace GUI
{
    public partial class JoinRoom : Form
    {
        public JoinRoom()
        {
            InitializeComponent();
        }

        private void buttonRoomInfo_Click(object sender, EventArgs e)
        {

        }

        private void buttonNext_Click(object sender, EventArgs e)
        {

        }

        private void JoinRoom_Load(object sender, EventArgs e)
        {

        }

        private void buttonRefresh_Click(object sender, EventArgs e)
        {
            if (Connector.sendMSG("getRooms", (int)Connector.Requests.Get_Rooms))
            {
                listViewRooms.Items.Clear();
                string rooms = Connector.recvMSG();
                rooms = rooms.Substring(rooms.IndexOf("i"));
                string room = "";
                for(int i = 0; i < rooms.Length; i++)
                {
                    if (rooms[i] == '/')
                    {                        
                        listViewRooms.Items.Add(room);
                        room = "";
                    }
                    else
                    {
                        room += rooms[i];
                    }
                }                
            }
            else
            {
                MessageBox.Show("Failed communicating with server", "Server Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void listViewRooms_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}
