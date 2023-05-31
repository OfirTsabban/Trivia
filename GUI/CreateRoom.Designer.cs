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
            this.textBoxTime = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.textBoxNumberPlayers = new System.Windows.Forms.TextBox();
            this.buttonRoomInfo = new System.Windows.Forms.Button();
            this.buttonNext = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Showcard Gothic", 48F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(86, 24);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(580, 98);
            this.label1.TabIndex = 0;
            this.label1.Text = "Create Room";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Showcard Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(124, 166);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(178, 35);
            this.label2.TabIndex = 1;
            this.label2.Text = "Room Name";
            // 
            // textBoxRoomName
            // 
            this.textBoxRoomName.BackColor = System.Drawing.Color.FloralWhite;
            this.textBoxRoomName.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBoxRoomName.ForeColor = System.Drawing.Color.DarkRed;
            this.textBoxRoomName.Location = new System.Drawing.Point(413, 165);
            this.textBoxRoomName.Name = "textBoxRoomName";
            this.textBoxRoomName.Size = new System.Drawing.Size(211, 36);
            this.textBoxRoomName.TabIndex = 2;
            this.textBoxRoomName.Text = "ENTER NAME...";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Showcard Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(124, 219);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(285, 35);
            this.label3.TabIndex = 3;
            this.label3.Text = "TIME FOR QUESTION";
            // 
            // textBoxTime
            // 
            this.textBoxTime.BackColor = System.Drawing.Color.FloralWhite;
            this.textBoxTime.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBoxTime.ForeColor = System.Drawing.Color.DarkRed;
            this.textBoxTime.Location = new System.Drawing.Point(416, 219);
            this.textBoxTime.Name = "textBoxTime";
            this.textBoxTime.Size = new System.Drawing.Size(208, 36);
            this.textBoxTime.TabIndex = 4;
            this.textBoxTime.Text = "ENTER TIME...";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Showcard Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(124, 272);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(256, 35);
            this.label4.TabIndex = 5;
            this.label4.Text = "PLAYERS NUMBER";
            // 
            // textBoxNumberPlayers
            // 
            this.textBoxNumberPlayers.BackColor = System.Drawing.Color.FloralWhite;
            this.textBoxNumberPlayers.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBoxNumberPlayers.ForeColor = System.Drawing.Color.DarkRed;
            this.textBoxNumberPlayers.Location = new System.Drawing.Point(413, 273);
            this.textBoxNumberPlayers.Name = "textBoxNumberPlayers";
            this.textBoxNumberPlayers.Size = new System.Drawing.Size(208, 36);
            this.textBoxNumberPlayers.TabIndex = 6;
            this.textBoxNumberPlayers.Text = "ENTER NUMBER...";
            // 
            // buttonRoomInfo
            // 
            this.buttonRoomInfo.BackColor = System.Drawing.Color.FloralWhite;
            this.buttonRoomInfo.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonRoomInfo.Location = new System.Drawing.Point(166, 349);
            this.buttonRoomInfo.Name = "buttonRoomInfo";
            this.buttonRoomInfo.Size = new System.Drawing.Size(170, 47);
            this.buttonRoomInfo.TabIndex = 7;
            this.buttonRoomInfo.Text = "ROOM INFO";
            this.buttonRoomInfo.UseVisualStyleBackColor = false;
            this.buttonRoomInfo.Click += new System.EventHandler(this.buttonRoomInfo_Click);
            // 
            // buttonNext
            // 
            this.buttonNext.BackColor = System.Drawing.Color.FloralWhite;
            this.buttonNext.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonNext.Location = new System.Drawing.Point(381, 349);
            this.buttonNext.Name = "buttonNext";
            this.buttonNext.Size = new System.Drawing.Size(170, 47);
            this.buttonNext.TabIndex = 8;
            this.buttonNext.Text = "NEXT";
            this.buttonNext.UseVisualStyleBackColor = false;
            this.buttonNext.Click += new System.EventHandler(this.buttonNext_Click);
            // 
            // CreateRoom
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.LemonChiffon;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.buttonNext);
            this.Controls.Add(this.buttonRoomInfo);
            this.Controls.Add(this.textBoxNumberPlayers);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.textBoxTime);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.textBoxRoomName);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.ForeColor = System.Drawing.Color.DarkRed;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
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
        private System.Windows.Forms.TextBox textBoxTime;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox textBoxNumberPlayers;
        private System.Windows.Forms.Button buttonRoomInfo;
        private System.Windows.Forms.Button buttonNext;
    }
}