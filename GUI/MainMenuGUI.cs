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
    public partial class Form1 : Form
    {
        private string user;
        public Form1(string user)
        {
            InitializeComponent();
            this.user = user;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

        private void buttonJoinRoom_Click(object sender, EventArgs e)
        {
            JoinRoom joinRoom = new JoinRoom(this.user);
            Hide();
            joinRoom.Show();
        }

        private void buttonClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void buttonStatistics_Click(object sender, EventArgs e)
        {
            Statistics statistics = new Statistics(this.user);
            Hide();
            statistics.Show();
        }

        private void buttonCreateRoom_Click(object sender, EventArgs e)
        {
            CreateRoom createRoom = new CreateRoom(this.user);
            Hide();
            createRoom.Show();
        }
    }
}
