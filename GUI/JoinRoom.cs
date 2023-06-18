using System;
using System.Drawing;
using System.Threading;
using System.Windows.Forms;

namespace GUI
{
    public partial class JoinRoom : Form
    {
        private string user;
        private int id;
        private string room;
        private bool refresh;
        public JoinRoom(string user)
        {
            InitializeComponent();
            this.user = user;
            this.refresh = true;
        }
        private string getRoom()
        {
            for (int i = 0; i < this.listViewRooms.Items.Count; i++)
            {
                string room = this.listViewRooms.Items[i].Text;
                string id = room.Substring(room.IndexOf("id: " + 4));
                id = id.Substring(id.IndexOf(","));
                if (int.Parse(id) == this.id)
                {
                    room = room.Substring(room.IndexOf("name: ") + 6);
                    room = room.Substring(room.IndexOf(","));
                    return room;
                } 
            }
            return "";
        }

        private void buttonRoomInfo_Click(object sender, EventArgs e)
        {

        }

        private void buttonNext_Click(object sender, EventArgs e)
        {
            bool error = false;
            string roomId = this.textBoxRoomId.Text;
            if (roomId == "")
            {
                MessageBox.Show("you have to claim room id", "room id", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
            else
            {
                for (int i = 0; i < roomId.Length; i++)
                {
                    if (!char.IsDigit(roomId, i))
                    {
                        MessageBox.Show("room id can only contain numbers", "room id", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                        error = true;
                    }
                }
                if (!error)
                {
                    this.id = int.Parse(roomId);
                    string json = Protocol.joinRoomProtocol(id);
                    if (Connector.sendMSG(json, (int)Connector.Requests.Join_Room))
                    {
                        string joined = Connector.recvMSG();
                      
                        if (joined.Contains("1"))
                        {
                            this.room = getRoom();
                            RoomInfo roomInfo = new RoomInfo(this.id, this.user, this.room);
                            Hide();
                            roomInfo.Show();
                        }
                        else if (joined.Contains("0"))
                        {
                            MessageBox.Show("Failed communicating with server", "Server Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        }

                    }
                    else
                    {
                        MessageBox.Show("Failed communicating with server", "Server Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }
                }
            }

        }

        private void JoinRoom_Load(object sender, EventArgs e)
        {
            this.labelName.Text = this.user;
            Thread refreshJoin = new Thread(new ThreadStart(refreshRoomsAuto));
            refreshJoin.Name = "RoomRefresher";
            refreshJoin.Start();
        }

        private void buttonRefresh_Click(object sender, EventArgs e)
        {
            if (Connector.sendMSG("getRooms", (int)Connector.Requests.Get_Rooms))
            {
                listViewRooms.Items.Clear();
                string rooms = Connector.recvMSG();
                if (rooms.Contains("i"))
                {
                    rooms = rooms.Substring(rooms.IndexOf("i"));
                    string room = "";
                    for (int i = 0; i < rooms.Length; i++)
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
                    MessageBox.Show("No rooms have been created yet", "Cant join", MessageBoxButtons.OK, MessageBoxIcon.Warning);
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
            string json = Protocol.joinRoomProtocol(id);
            if (Connector.sendMSG(json, (int)Connector.Requests.Join_Room))
            {
                string joined = Connector.recvMSG();
                this.room = getRoom();
                RoomInfo roomInfo = new RoomInfo(id, this.user, this.room);
                Hide();
                roomInfo.Show();

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

        private void textBoxRoomId_TextChanged(object sender, EventArgs e)
        {

        }

        private void refreshRoomsAuto()
        {
            while (this.refresh)
            {
                if (Connector.sendMSG("getRooms", (int)Connector.Requests.Get_Rooms))
                {
                    this.Invoke((MethodInvoker)delegate
                    {
                        listViewRooms.Items.Clear();
                        string rooms = Connector.recvMSG();
                        if (rooms.Contains("i"))
                        {
                            rooms = rooms.Substring(rooms.IndexOf("i"));
                            string room = "";
                            for (int i = 0; i < rooms.Length; i++)
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
                    });

                }
                else
                {
                    MessageBox.Show("Failed communicating with server", "Server Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                Thread.Sleep(3000);
            }
        }

        private void labelName_Click(object sender, EventArgs e)
        {

        }
    }
}
