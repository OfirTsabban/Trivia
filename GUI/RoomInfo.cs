using System;
using System.Linq;
using System.Threading;
using System.Windows.Forms;

namespace GUI
{
    public partial class RoomInfo : Form
    {
        private int roomId;
        private bool refresh;
        private string user;
        private bool hasGameBegun = false;
        private static Mutex mutex;
        Thread refreshPlayers;
        Thread waitAction;

        public RoomInfo(int id, string userName)
        {
            this.user = userName;
            this.roomId = id;
            this.refresh = true;
            mutex = new Mutex();
            refreshPlayers = new Thread(new ThreadStart(getPlayers));
            waitAction = new Thread(new ThreadStart(getAction));
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
            this.labelName.Text = this.user;
            
            refreshPlayers.Name = "RoomInfoRefresher";
            refreshPlayers.Start();
           
            waitAction.Name = "waitForAction";
            waitAction.Start();
        }

        private void buttonStart_Click(object sender, EventArgs e)
        {
            if (this.user == this.LabelAdminName.Text)
            {
                if (Connector.sendMSG("Start Game", (int)Connector.Requests.Admin_Start_Game))
                {
                    this.hasGameBegun = true;
                    this.refresh = false;
                    MessageBox.Show("Host started game", "success", MessageBoxButtons.OK);
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
            this.refreshPlayers.Abort();
            this.waitAction.Abort();
            if (this.user == this.LabelAdminName.Text)
            {
                if (Connector.sendMSG("CloseRoom", (int)Connector.Requests.Close_Room))
                {
                    string msg = Connector.recvMSG();
                    if (msg.Contains("CloseRoom") || msg.Contains("LeaveRoom"))
                    {
                        this.refresh = false;
                        MessageBox.Show("Host closed room", "Update", MessageBoxButtons.OK, MessageBoxIcon.Information);
                        Form1 mainMenu = new Form1(this.user);
                        Hide();
                        mainMenu.Show();
                    }
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
                    this.refresh = false;
                    string msg = Connector.recvMSG();
                    MessageBox.Show(this.user + " has left the room", "Update", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    Form1 mainMenu = new Form1(this.user);
                    Hide();
                    mainMenu.Show();
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
                msg = msg.Substring(msg.IndexOf(":") + 2);
                msg = msg.Substring(0, msg.IndexOf('"'));
                string message = "";
                for (int i = 0; i < msg.Length; i++)
                {
                    if (msg[i] == '/')
                    {
                        message += "\n";
                    }
                    else
                    {
                        message += msg[i];
                    }
                }
                MessageBox.Show(message, "Room State", MessageBoxButtons.OK);
            }
            else
            {
                MessageBox.Show("Failed communicating with server", "Server Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void getAction()
        {
            string msg = "";

            while (this.refresh)
            {
                mutex.WaitOne();
                Connector.sendMSG("GetRoomState", (int)Connector.Requests.Room_State);
                Thread.Sleep(200);
                msg = Connector.recvMSG();
                mutex.ReleaseMutex();
                if(msg.Contains("has game begun: 1"))
                {
                    this.refresh = false;
                    MessageBox.Show("Host started game", "success", MessageBoxButtons.OK);
                }
                if (msg.Contains("get out"))
                {
                    this.refresh = false;
                    MessageBox.Show("Host started game", "success", MessageBoxButtons.OK);
                    Form1 mainMenu = new Form1(this.user);
                    Hide();
                    mainMenu.Show();
                }
            }
            
        }
        private void getPlayers()
        {
            while (this.refresh)
            {
                string json = Protocol.getPlayersProtocol(this.roomId);
                mutex.WaitOne();
                if (Connector.sendMSG(json, (int)Connector.Requests.Get_Players))
                {
                    this.Invoke((MethodInvoker)delegate
                    {
                        this.listViewPlayers.Items.Clear();
                        Thread.Sleep(200);
                        string players = Connector.recvMSG();
                        players = players.Substring(players.IndexOf(':') + 2);
                        if (players.Contains(','))
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
                    });
                }
                else
                {
                    MessageBox.Show("Failed communicating with server", "Server Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                mutex.ReleaseMutex();
                Thread.Sleep(3000);
            }
        }
    }
}
