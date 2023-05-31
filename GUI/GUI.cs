using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

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

        }

        private void password_TextChanged(object sender, EventArgs e)
        {

        }

        private void buttonStart_Click(object sender, EventArgs e)
        {
            Form1 mainMenu = new Form1();
            mainMenu.Show();//need to delete the other screen
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
            //need to delete the other screen
        }

        private void GUI_Load(object sender, EventArgs e)
        {

        }        
    }
}
