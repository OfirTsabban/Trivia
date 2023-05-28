namespace GUI
{
    partial class GUI
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.triviaLabel = new System.Windows.Forms.Label();
            this.userLabel = new System.Windows.Forms.Label();
            this.passLabel = new System.Windows.Forms.Label();
            this.userName = new System.Windows.Forms.TextBox();
            this.password = new System.Windows.Forms.TextBox();
            this.buttonStart = new System.Windows.Forms.Button();
            this.toSignupLabel = new System.Windows.Forms.Label();
            this.buttonSignup = new System.Windows.Forms.Button();
            this.buttonClose = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // triviaLabel
            // 
            this.triviaLabel.AutoSize = true;
            this.triviaLabel.Font = new System.Drawing.Font("Showcard Gothic", 48F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.triviaLabel.ForeColor = System.Drawing.Color.DarkRed;
            this.triviaLabel.Location = new System.Drawing.Point(329, 57);
            this.triviaLabel.Name = "triviaLabel";
            this.triviaLabel.Size = new System.Drawing.Size(310, 98);
            this.triviaLabel.TabIndex = 0;
            this.triviaLabel.Text = "TRIVIA";
            // 
            // userLabel
            // 
            this.userLabel.AutoSize = true;
            this.userLabel.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.userLabel.ForeColor = System.Drawing.Color.DarkRed;
            this.userLabel.Location = new System.Drawing.Point(302, 207);
            this.userLabel.Name = "userLabel";
            this.userLabel.Size = new System.Drawing.Size(135, 29);
            this.userLabel.TabIndex = 1;
            this.userLabel.Text = "USER NAME";
            // 
            // passLabel
            // 
            this.passLabel.AutoSize = true;
            this.passLabel.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.passLabel.ForeColor = System.Drawing.Color.DarkRed;
            this.passLabel.Location = new System.Drawing.Point(302, 264);
            this.passLabel.Name = "passLabel";
            this.passLabel.Size = new System.Drawing.Size(140, 29);
            this.passLabel.TabIndex = 2;
            this.passLabel.Text = "PASSWORD";
            // 
            // userName
            // 
            this.userName.BackColor = System.Drawing.Color.FloralWhite;
            this.userName.Font = new System.Drawing.Font("Showcard Gothic", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.userName.ForeColor = System.Drawing.Color.DarkRed;
            this.userName.Location = new System.Drawing.Point(459, 214);
            this.userName.Name = "userName";
            this.userName.Size = new System.Drawing.Size(171, 24);
            this.userName.TabIndex = 3;
            this.userName.Text = "ENTER USERNAME...\r\n";
            this.userName.TextChanged += new System.EventHandler(this.userName_TextChanged);
            // 
            // password
            // 
            this.password.BackColor = System.Drawing.Color.FloralWhite;
            this.password.Font = new System.Drawing.Font("Showcard Gothic", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.password.ForeColor = System.Drawing.Color.DarkRed;
            this.password.Location = new System.Drawing.Point(459, 270);
            this.password.Name = "password";
            this.password.Size = new System.Drawing.Size(171, 24);
            this.password.TabIndex = 4;
            this.password.Text = "......";
            this.password.UseSystemPasswordChar = true;
            this.password.TextChanged += new System.EventHandler(this.password_TextChanged);
            // 
            // buttonStart
            // 
            this.buttonStart.BackColor = System.Drawing.Color.FloralWhite;
            this.buttonStart.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonStart.ForeColor = System.Drawing.Color.DarkRed;
            this.buttonStart.Location = new System.Drawing.Point(346, 343);
            this.buttonStart.Name = "buttonStart";
            this.buttonStart.Size = new System.Drawing.Size(111, 54);
            this.buttonStart.TabIndex = 5;
            this.buttonStart.Text = "START";
            this.buttonStart.UseVisualStyleBackColor = false;
            this.buttonStart.Click += new System.EventHandler(this.buttonStart_Click);
            // 
            // toSignupLabel
            // 
            this.toSignupLabel.AutoSize = true;
            this.toSignupLabel.Font = new System.Drawing.Font("Showcard Gothic", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.toSignupLabel.ForeColor = System.Drawing.Color.DarkRed;
            this.toSignupLabel.Location = new System.Drawing.Point(252, 434);
            this.toSignupLabel.Name = "toSignupLabel";
            this.toSignupLabel.Size = new System.Drawing.Size(306, 18);
            this.toSignupLabel.TabIndex = 6;
            this.toSignupLabel.Text = "dont have an account? press here to";
            // 
            // buttonSignup
            // 
            this.buttonSignup.BackColor = System.Drawing.Color.LemonChiffon;
            this.buttonSignup.Font = new System.Drawing.Font("Showcard Gothic", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonSignup.ForeColor = System.Drawing.Color.DarkRed;
            this.buttonSignup.Location = new System.Drawing.Point(555, 432);
            this.buttonSignup.Name = "buttonSignup";
            this.buttonSignup.Size = new System.Drawing.Size(75, 23);
            this.buttonSignup.TabIndex = 7;
            this.buttonSignup.Text = "sign-up";
            this.buttonSignup.UseVisualStyleBackColor = false;
            this.buttonSignup.Click += new System.EventHandler(this.buttonSignup_Click);
            // 
            // buttonClose
            // 
            this.buttonClose.BackColor = System.Drawing.Color.FloralWhite;
            this.buttonClose.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonClose.Location = new System.Drawing.Point(483, 343);
            this.buttonClose.Name = "buttonClose";
            this.buttonClose.Size = new System.Drawing.Size(110, 54);
            this.buttonClose.TabIndex = 8;
            this.buttonClose.Text = "CLOSE";
            this.buttonClose.UseVisualStyleBackColor = false;
            this.buttonClose.Click += new System.EventHandler(this.button1_Click);
            // 
            // GUI
            // 
            this.BackColor = System.Drawing.Color.LemonChiffon;
            this.ClientSize = new System.Drawing.Size(1000, 534);
            this.Controls.Add(this.buttonClose);
            this.Controls.Add(this.buttonSignup);
            this.Controls.Add(this.toSignupLabel);
            this.Controls.Add(this.buttonStart);
            this.Controls.Add(this.password);
            this.Controls.Add(this.userName);
            this.Controls.Add(this.passLabel);
            this.Controls.Add(this.userLabel);
            this.Controls.Add(this.triviaLabel);
            this.ForeColor = System.Drawing.Color.DarkRed;
            this.Name = "GUI";
            this.Text = "Trivia-Itay&Ofir";
            this.TransparencyKey = System.Drawing.Color.DarkRed;
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label userNameLabel;
        private System.Windows.Forms.Label passwordLabel;
        private System.Windows.Forms.Label triviaLabel;
        private System.Windows.Forms.Label userLabel;
        private System.Windows.Forms.Label passLabel;
        private System.Windows.Forms.TextBox userName;
        private System.Windows.Forms.TextBox password;
        private System.Windows.Forms.Button buttonStart;
        private System.Windows.Forms.Label toSignupLabel;
        private System.Windows.Forms.Button buttonSignup;
        private System.Windows.Forms.Button buttonClose;
    }
}

