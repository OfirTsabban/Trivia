namespace GUI
{
    partial class CreateRoom
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(CreateRoom));
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.textBoxRoomName = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.buttonNext = new System.Windows.Forms.Button();
            this.cboTime = new System.Windows.Forms.ComboBox();
            this.cboPlayersNum = new System.Windows.Forms.ComboBox();
            this.label5 = new System.Windows.Forms.Label();
            this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            this.cboNumberQuestions = new System.Windows.Forms.ComboBox();
            this.buttonBack = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Showcard Gothic", 48F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(160, 21);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(580, 98);
            this.label1.TabIndex = 0;
            this.label1.Text = "Create Room";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Showcard Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(213, 168);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(178, 35);
            this.label2.TabIndex = 1;
            this.label2.Text = "Room Name";
            // 
            // textBoxRoomName
            // 
            this.textBoxRoomName.BackColor = System.Drawing.Color.FloralWhite;
            this.textBoxRoomName.Font = new System.Drawing.Font("Showcard Gothic", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBoxRoomName.ForeColor = System.Drawing.Color.DarkRed;
            this.textBoxRoomName.Location = new System.Drawing.Point(555, 168);
            this.textBoxRoomName.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.textBoxRoomName.Multiline = true;
            this.textBoxRoomName.Name = "textBoxRoomName";
            this.textBoxRoomName.Size = new System.Drawing.Size(211, 30);
            this.textBoxRoomName.TabIndex = 2;
            this.textBoxRoomName.Text = "ENTER NAME...";
            this.textBoxRoomName.TextChanged += new System.EventHandler(this.textBoxRoomName_TextChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Showcard Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(213, 219);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(285, 35);
            this.label3.TabIndex = 3;
            this.label3.Text = "TIME FOR QUESTION";
            this.label3.Click += new System.EventHandler(this.label3_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Showcard Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(213, 267);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(256, 35);
            this.label4.TabIndex = 5;
            this.label4.Text = "PLAYERS NUMBER";
            // 
            // buttonNext
            // 
            this.buttonNext.BackColor = System.Drawing.Color.FloralWhite;
            this.buttonNext.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonNext.Location = new System.Drawing.Point(241, 398);
            this.buttonNext.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.buttonNext.Name = "buttonNext";
            this.buttonNext.Size = new System.Drawing.Size(199, 67);
            this.buttonNext.TabIndex = 8;
            this.buttonNext.Text = "NEXT";
            this.buttonNext.UseVisualStyleBackColor = false;
            this.buttonNext.Click += new System.EventHandler(this.buttonNext_Click);
            // 
            // cboTime
            // 
            this.cboTime.AccessibleRole = System.Windows.Forms.AccessibleRole.ScrollBar;
            this.cboTime.BackColor = System.Drawing.Color.FloralWhite;
            this.cboTime.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cboTime.ForeColor = System.Drawing.Color.DarkRed;
            this.cboTime.FormattingEnabled = true;
            this.cboTime.Items.AddRange(new object[] {
            "10",
            "15",
            "20",
            "25",
            "30",
            "40",
            "45",
            "5"});
            this.cboTime.Location = new System.Drawing.Point(555, 231);
            this.cboTime.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.cboTime.Name = "cboTime";
            this.cboTime.Size = new System.Drawing.Size(211, 24);
            this.cboTime.TabIndex = 9;
            this.cboTime.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
            // 
            // cboPlayersNum
            // 
            this.cboPlayersNum.BackColor = System.Drawing.Color.FloralWhite;
            this.cboPlayersNum.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cboPlayersNum.ForeColor = System.Drawing.Color.DarkRed;
            this.cboPlayersNum.FormattingEnabled = true;
            this.cboPlayersNum.Items.AddRange(new object[] {
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8",
            "9",
            "10"});
            this.cboPlayersNum.Location = new System.Drawing.Point(555, 279);
            this.cboPlayersNum.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.cboPlayersNum.Name = "cboPlayersNum";
            this.cboPlayersNum.Size = new System.Drawing.Size(211, 24);
            this.cboPlayersNum.TabIndex = 10;
            this.cboPlayersNum.SelectedIndexChanged += new System.EventHandler(this.cboPlayersNum_SelectedIndexChanged);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Showcard Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(213, 315);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(329, 35);
            this.label5.TabIndex = 11;
            this.label5.Text = "NUMBER OF QUESTIONS";
            // 
            // cboNumberQuestions
            // 
            this.cboNumberQuestions.BackColor = System.Drawing.Color.FloralWhite;
            this.cboNumberQuestions.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cboNumberQuestions.ForeColor = System.Drawing.Color.DarkRed;
            this.cboNumberQuestions.FormattingEnabled = true;
            this.cboNumberQuestions.Items.AddRange(new object[] {
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8",
            "9",
            "10"});
            this.cboNumberQuestions.Location = new System.Drawing.Point(555, 326);
            this.cboNumberQuestions.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.cboNumberQuestions.Name = "cboNumberQuestions";
            this.cboNumberQuestions.Size = new System.Drawing.Size(211, 24);
            this.cboNumberQuestions.TabIndex = 12;
            // 
            // buttonBack
            // 
            this.buttonBack.BackColor = System.Drawing.Color.FloralWhite;
            this.buttonBack.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonBack.Location = new System.Drawing.Point(525, 398);
            this.buttonBack.Name = "buttonBack";
            this.buttonBack.Size = new System.Drawing.Size(199, 67);
            this.buttonBack.TabIndex = 13;
            this.buttonBack.Text = "BACK";
            this.buttonBack.UseVisualStyleBackColor = false;
            this.buttonBack.Click += new System.EventHandler(this.buttonBack_Click);
            // 
            // CreateRoom
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.LemonChiffon;
            this.ClientSize = new System.Drawing.Size(930, 531);
            this.Controls.Add(this.buttonBack);
            this.Controls.Add(this.cboNumberQuestions);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.cboPlayersNum);
            this.Controls.Add(this.cboTime);
            this.Controls.Add(this.buttonNext);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.textBoxRoomName);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.ForeColor = System.Drawing.Color.DarkRed;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.Name = "CreateRoom";
            this.Text = "Trivia-create room";
            this.Load += new System.EventHandler(this.CreateRoom_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBoxRoomName;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button buttonNext;
        private System.Windows.Forms.ComboBox cboTime;
        private System.Windows.Forms.ComboBox cboPlayersNum;
        private System.Windows.Forms.Label label5;
        private System.ComponentModel.BackgroundWorker backgroundWorker1;
        private System.Windows.Forms.ComboBox cboNumberQuestions;
        private System.Windows.Forms.Button buttonBack;
    }
}