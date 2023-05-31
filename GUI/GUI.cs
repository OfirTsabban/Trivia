using System;
using System.Windows.Forms;

namespace GUI
{
    public partial class GUI : Form
    {
        public GUI()
        {
            InitializeComponent();
        }

        private void userName_TextChanged(object sender, EventArgs e)
        {
            string text = userName.Text;
        }

        private void password_TextChanged(object sender, EventArgs e)
        {
            string pass = password.Text;
            Console.WriteLine(pass);
        }

        private void buttonStart_Click(object sender, EventArgs e)
        {
            Form1 mainMenu = new Form1();
            Hide();
            mainMenu.Show();
        }

        private void buttonSignup_Click(object sender, EventArgs e)
        {
            //ignore
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            signupGUI signup = new signupGUI();
            Hide();
            signup.Show();
        }

        private void GUI_Load(object sender, EventArgs e)
        {

        }
    }
}
