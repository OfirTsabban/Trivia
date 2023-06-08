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
            RoomInfo roomInfo = new RoomInfo();
            Hide();
            roomInfo.Show();
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
            listViewRooms.ColumnClick += ListViewRooms_ColumnClick;
        }

        private void ListViewRooms_ColumnClick(object sender, ColumnClickEventArgs e)
        {
            string column = e.ToString();
            //dont get admin nor players yet...
        }

        private void buttonBack_Click(object sender, EventArgs e)
        {
            Form1 mainMenu = new Form1();
            Hide();
            mainMenu.Show();
        }
    }
}
