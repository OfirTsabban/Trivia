using System;
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
                string rooms = Connector.recvMSG();
                rooms = rooms.Substring(rooms.IndexOf("{"));
                rooms = rooms;
            }
            else
            {
                MessageBox.Show("Failed communicating with server", "Server Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
