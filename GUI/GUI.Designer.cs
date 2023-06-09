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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(GUI));
            this.triviaLabel = new System.Windows.Forms.Label();
            this.userLabel = new System.Windows.Forms.Label();
            this.passLabel = new System.Windows.Forms.Label();
            this.userName = new System.Windows.Forms.TextBox();
            this.password = new System.Windows.Forms.TextBox();
            this.buttonStart = new System.Windows.Forms.Button();
            this.toSignupLabel = new System.Windows.Forms.Label();
            this.buttonClose = new System.Windows.Forms.Button();
            this.linkLabelSignup = new System.Windows.Forms.LinkLabel();
            this.SuspendLayout();
            // 
            // triviaLabel
            // 
            resources.ApplyResources(this.triviaLabel, "triviaLabel");
            this.triviaLabel.ForeColor = System.Drawing.Color.DarkRed;
            this.triviaLabel.Name = "triviaLabel";
            // 
            // userLabel
            // 
            resources.ApplyResources(this.userLabel, "userLabel");
            this.userLabel.ForeColor = System.Drawing.Color.DarkRed;
            this.userLabel.Name = "userLabel";
            // 
            // passLabel
            // 
            resources.ApplyResources(this.passLabel, "passLabel");
            this.passLabel.ForeColor = System.Drawing.Color.DarkRed;
            this.passLabel.Name = "passLabel";
            // 
            // userName
            // 
            this.userName.BackColor = System.Drawing.Color.FloralWhite;
            resources.ApplyResources(this.userName, "userName");
            this.userName.ForeColor = System.Drawing.Color.DarkRed;
            this.userName.Name = "userName";
            this.userName.TextChanged += new System.EventHandler(this.userName_TextChanged);
            // 
            // password
            // 
            this.password.BackColor = System.Drawing.Color.FloralWhite;
            resources.ApplyResources(this.password, "password");
            this.password.ForeColor = System.Drawing.Color.DarkRed;
            this.password.Name = "password";
            this.password.UseSystemPasswordChar = true;
            this.password.TextChanged += new System.EventHandler(this.password_TextChanged);
            // 
            // buttonStart
            // 
            this.buttonStart.BackColor = System.Drawing.Color.FloralWhite;
            resources.ApplyResources(this.buttonStart, "buttonStart");
            this.buttonStart.ForeColor = System.Drawing.Color.DarkRed;
            this.buttonStart.Name = "buttonStart";
            this.buttonStart.UseVisualStyleBackColor = false;
            this.buttonStart.Click += new System.EventHandler(this.buttonStart_Click);
            // 
            // toSignupLabel
            // 
            resources.ApplyResources(this.toSignupLabel, "toSignupLabel");
            this.toSignupLabel.ForeColor = System.Drawing.Color.DarkRed;
            this.toSignupLabel.Name = "toSignupLabel";
            // 
            // buttonClose
            // 
            this.buttonClose.BackColor = System.Drawing.Color.FloralWhite;
            resources.ApplyResources(this.buttonClose, "buttonClose");
            this.buttonClose.Name = "buttonClose";
            this.buttonClose.UseVisualStyleBackColor = false;
            this.buttonClose.Click += new System.EventHandler(this.button1_Click);
            // 
            // linkLabelSignup
            // 
            this.linkLabelSignup.ActiveLinkColor = System.Drawing.Color.DarkRed;
            resources.ApplyResources(this.linkLabelSignup, "linkLabelSignup");
            this.linkLabelSignup.DisabledLinkColor = System.Drawing.Color.MistyRose;
            this.linkLabelSignup.LinkColor = System.Drawing.Color.DarkRed;
            this.linkLabelSignup.Name = "linkLabelSignup";
            this.linkLabelSignup.TabStop = true;
            this.linkLabelSignup.VisitedLinkColor = System.Drawing.Color.LightCoral;
            this.linkLabelSignup.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linkLabel1_LinkClicked);
            // 
            // GUI
            // 
            this.BackColor = System.Drawing.Color.LemonChiffon;
            resources.ApplyResources(this, "$this");
            this.Controls.Add(this.linkLabelSignup);
            this.Controls.Add(this.buttonClose);
            this.Controls.Add(this.toSignupLabel);
            this.Controls.Add(this.buttonStart);
            this.Controls.Add(this.password);
            this.Controls.Add(this.userName);
            this.Controls.Add(this.passLabel);
            this.Controls.Add(this.userLabel);
            this.Controls.Add(this.triviaLabel);
            this.Cursor = System.Windows.Forms.Cursors.Hand;
            this.ForeColor = System.Drawing.Color.DarkRed;
            this.Name = "GUI";
            this.TransparencyKey = System.Drawing.Color.DarkRed;
            this.Load += new System.EventHandler(this.GUI_Load);
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
        private System.Windows.Forms.Button buttonClose;
        private System.Windows.Forms.LinkLabel linkLabelSignup;
    }
}

