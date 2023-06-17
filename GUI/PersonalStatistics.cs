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
    public partial class PersonalStatistics : Form
    {
        private string user;
        public PersonalStatistics(string user)
        {
            this.user = user;
            InitializeComponent();
        }

        private void label2_Click(object sender, EventArgs e)
        {
            
        }

        private void PersonalStatistics_Load(object sender, EventArgs e)
        {
            this.label2.Text = this.user;
        }
    }
}
