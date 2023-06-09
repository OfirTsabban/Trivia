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
            this.listViewRooms.ColumnClick += ColumnClick;
            ColumnClickEventArgs args = new ColumnClickEventArgs(0);
            ColumnClick(this, args);
        }

        private void ColumnClick(object sender, ColumnClickEventArgs e)
        {
            this.SuspendLayout();
            int index = e.Column;            
            string column = this.listViewRooms.Items[index].ToString();                        
            column = column.Substring(column.IndexOf("id: ") + 4);
            column = column.Substring(0, column.IndexOf(','));             
            int id = int.Parse(column);            
            RoomInfo roomInfo = new RoomInfo(id);
            Hide();
            roomInfo.Show(); 
        }

        private void buttonBack_Click(object sender, EventArgs e)
        {
            Form1 mainMenu = new Form1();
            Hide();
            mainMenu.Show();
        }
    }
}
