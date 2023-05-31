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
<<<<<<< HEAD
            Form1 mainMenu = new Form1();
            Hide();
            mainMenu.Show();
=======
            bool error = false;
            int fieldsFilled = 0;

            string name = userName.Text;
            if (checkUsername(name) != "" && !error)
            {
                MessageBox.Show(checkUsername(name));
                error = true;
            }
            else
            {
                fieldsFilled++;
            }
            string pw = password.Text;
            if (chkPW(pw) != "" && !error)
            {
                MessageBox.Show(chkPW(pw));
                error = true;
            }
            else
            {
                fieldsFilled++;
            }

            if (fieldsFilled == 2)
            {
                Form1 mainMenu = new Form1();
                Hide();
                mainMenu.Show();
            }
            
>>>>>>> 9f42d60b1c1b240bde09a7eaf76d5cd709fcfd54
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
<<<<<<< HEAD
=======

        private string checkUsername(string userName)
        {
            if (userName.Length < 2)
            {
                return "Error - Username is too short";
            }
            else if (userName.Length > 30)
            {
                return "Error - Username is too long";
            }
            else if (containHebrew(userName))
            {
                return "Error - Username cant contain Hebrew";
            }
            else if (badChar(userName))
            {
                return "Error - Username cant contain special characters";
            }
            else if (isQuot(userName))
            {
                return "Error - Username cant contain special quotes";
            }

            return "";
        }

        private string chkPW(string pw)
        {
            if (pw.Length < 8)
            {
                return "Error - password cant be shorter than 8 characters";
            }
            else if (pw.Length > 30)
            {
                return "Error - password cant be longer than 30 characters";
            }
            else if (!chkPWConditions(pw))
            {
                return "Error - password need to contain a number, upper case letter and lower case letter";
            }
            else if (badChar(pw))
            {
                return "Error - password cant contain special characters";
            }

            return "";
        }

        bool containHebrew(string name)
        {
            for (int i = 0; i < name.Length; i++)
            {
                if (name[i] >= 'א' && name[i] <= 'ת')
                {
                    return true;
                }
            }

            return false;
        }

        bool badChar(string name)
        {
            string badChars = "~!@#$%^&*()+=-/|[,?]{}";

            for (int i = 0; i < name.Length; i++)
            {
                if (badChars.Contains(name[i]))
                {
                    return true;
                }
            }

            return false;
        }

        bool isQuot(string name)
        {
            char quot = '"'; string quot1 = "'";

            if (name.IndexOf(quot) != -1 || name.IndexOf(quot1) != -1)
                return true;
            return false;
        }

        bool chkPWConditions(string pw)
        {
            bool number = false, upper = false, lower = false;

            for (int i = 0; i < pw.Length; i++)
            {
                if (Char.IsDigit(pw[i]))
                {
                    number = true;
                }
                if (Char.IsUpper(pw[i]))
                {
                    upper = true;
                }
                if (Char.IsLower(pw[i]))
                {
                    lower = true;
                }
            }

            return number && upper && lower;
        }
>>>>>>> 9f42d60b1c1b240bde09a7eaf76d5cd709fcfd54
    }
}
