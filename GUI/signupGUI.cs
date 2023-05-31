using System;
using System.Linq;
using System.Text.RegularExpressions;
using System.Windows.Forms;

namespace GUI
{
    public partial class signupGUI : Form
    {
        public signupGUI()
        {
            InitializeComponent();
        }

        private void signupGUI_Load(object sender, EventArgs e)
        {

        }

        private void textBoxName_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBoxPassword_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBoxEmail_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBoxStreet_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBoxApt_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBoxPrefix_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBoxNumber_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBoxYearBorn_TextChanged(object sender, EventArgs e)
        {

        }

        private void buttonNext_Click(object sender, EventArgs e)
        {
<<<<<<< HEAD
            Form1 mainMenu = new Form1();
            Hide();
            mainMenu.Show();
=======
            bool error = false;
            int fieldsFilled = 0;

            string userName = textBoxName.Text;
            if (checkUsername(userName) != "" && !error)
            {
                MessageBox.Show(checkUsername(userName));
                error = true;
            }
            else
            {
                fieldsFilled++;
            }
            string password = textBoxPassword.Text;
            if (chkPW(password) != "" && !error)
            {
                MessageBox.Show(chkPW(password));
                error = true;
            }
            else
            {
                fieldsFilled++;
            }
            string email = textBoxEmail.Text;
            if (chkMail(email) != "" && !error)
            {
                MessageBox.Show(chkMail(email));
                error = true;
            }
            else
            {
                fieldsFilled++;
            }
            string street = textBoxStreet.Text;
            if (chkStreet(street) && !error)
            {
                MessageBox.Show("Error - write only name of the street");
                error = true;
            }
            else
            {
                fieldsFilled++;
            }
            string apt = textBoxApt.Text;
            int aptNum = 0;
            bool aptChk = int.TryParse(apt, out aptNum);
            if (aptChk == false && !error)
            {
                MessageBox.Show("Error - apt need to be a number");
                error = true;
            }
            else
            {
                fieldsFilled++;
            }
            string prefix = textBoxPrefix.Text;
            if (!(Regex.IsMatch(prefix, "^(050|052|053|054|055|057|058|02|03|04|08|09|077)")) && !error)
            {
                MessageBox.Show("Error - prefix havnt fount");
                error = true;
            }
            else
            {
                fieldsFilled++;
            }
            string number = textBoxNumber.Text;
            if (chkNumber(number) != "" && !error)
            {
                MessageBox.Show(chkNumber(number));
                error = true;
            }
            else
            {
                fieldsFilled++;
            }

            string year = textBoxYearBorn.Text;
            if (chkYear(year) != "" && !error)
            {
                MessageBox.Show(chkYear(year));
                error = true;
            }
            else
            {
                fieldsFilled++;
            }

            if (fieldsFilled == 8)
            {
                Form1 mainMenu = new Form1();
                Hide();
                mainMenu.Show();
            }
        }

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

        private string chkMail(string mail)
        {
            if (mail.Length < 6 || mail.Length > 30)
            {
                return "Error - email is too short or too long";
            }
            else if (mail.IndexOf('@') == -1)
            {
                return "Error - @ sign wasnt found";
            }
            else if (mail.IndexOf('@') != mail.LastIndexOf('@'))
            {
                return "Error - @ sign cannot appear twice";
            }
            else if (mail.IndexOf('@') < 2 || mail.LastIndexOf('@') == mail.Length - 1)
            {
                return "Error - @ sign cannot appear at the beggining or at the end";
            }
            else if (mail.IndexOf('.') == 0 || mail.LastIndexOf('.') == mail.Length - 1)
            {
                return "Error - dot cannot appear at the beggining or at the end";
            }
            else if (mail.IndexOf('.', mail.IndexOf('@')) - mail.IndexOf('@') <= 1)
            {
                return "Error - dot need to be at least 2 characters away from @ sign";
            }

            return "";
        }

        private bool chkStreet(string street)
        {
            bool number = false;
            for (int i = 0; i < street.Length; i++)
            {
                if (Char.IsDigit(street[i]))
                {
                    number = true;
                }
            }

            return number;
        }

        private string chkNumber(string number)
        {
            int numberVerifier = 0;
            bool numberChk = int.TryParse(number, out numberVerifier);

            if (number.Length != 7)
            {
                return "Error - phone number length need to be 7";
            }
            else if (!numberChk)
            {
                return "Error - phone number can only contain numbers";
            }

            return "";
        }

        private string chkYear(string year)
        {
            int yearVerifier = 0;
            bool yearChk = int.TryParse(year, out yearVerifier);

            if (year.Length != 4)
            {
                return "Error - year doesnt make sense";
            }
            else if (!yearChk)
            {
                return "Error - year can only contain numbers";
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
>>>>>>> 9f42d60b1c1b240bde09a7eaf76d5cd709fcfd54
        }
    }
}