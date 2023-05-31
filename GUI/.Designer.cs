namespace GUI
{
    partial class Form1
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.buttonClose = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.buttonCreateRoom = new System.Windows.Forms.Button();
            this.buttonJoinRoom = new System.Windows.Forms.Button();
            this.buttonStatistics = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // buttonClose
            // 
            this.buttonClose.BackColor = System.Drawing.Color.FloralWhite;
            this.buttonClose.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonClose.ForeColor = System.Drawing.Color.DarkRed;
            this.buttonClose.Location = new System.Drawing.Point(596, 378);
            this.buttonClose.Name = "buttonClose";
            this.buttonClose.Size = new System.Drawing.Size(213, 130);
            this.buttonClose.TabIndex = 0;
            this.buttonClose.Text = "CLOSE";
            this.buttonClose.UseVisualStyleBackColor = false;
            this.buttonClose.Click += new System.EventHandler(this.buttonClose_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Showcard Gothic", 48F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.DarkRed;
            this.label1.Location = new System.Drawing.Point(413, 42);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(261, 98);
            this.label1.TabIndex = 1;
            this.label1.Text = "MENU";
            // 
            // buttonCreateRoom
            // 
            this.buttonCreateRoom.BackColor = System.Drawing.Color.FloralWhite;
            this.buttonCreateRoom.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonCreateRoom.ForeColor = System.Drawing.Color.DarkRed;
            this.buttonCreateRoom.Location = new System.Drawing.Point(268, 378);
            this.buttonCreateRoom.Name = "buttonCreateRoom";
            this.buttonCreateRoom.Size = new System.Drawing.Size(215, 130);
            this.buttonCreateRoom.TabIndex = 2;
            this.buttonCreateRoom.Text = "CREATE ROOM";
            this.buttonCreateRoom.UseVisualStyleBackColor = false;
            this.buttonCreateRoom.Click += new System.EventHandler(this.buttonCreateRoom_Click);
            // 
            // buttonJoinRoom
            // 
            this.buttonJoinRoom.BackColor = System.Drawing.Color.FloralWhite;
            this.buttonJoinRoom.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonJoinRoom.ForeColor = System.Drawing.Color.DarkRed;
            this.buttonJoinRoom.Location = new System.Drawing.Point(596, 189);
            this.buttonJoinRoom.Name = "buttonJoinRoom";
            this.buttonJoinRoom.Size = new System.Drawing.Size(213, 119);
            this.buttonJoinRoom.TabIndex = 3;
            this.buttonJoinRoom.Text = "JOIN ROOM";
            this.buttonJoinRoom.UseVisualStyleBackColor = false;
            this.buttonJoinRoom.Click += new System.EventHandler(this.buttonJoinRoom_Click);
            // 
            // buttonStatistics
            // 
            this.buttonStatistics.BackColor = System.Drawing.Color.FloralWhite;
            this.buttonStatistics.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonStatistics.ForeColor = System.Drawing.Color.DarkRed;
            this.buttonStatistics.Location = new System.Drawing.Point(268, 189);
            this.buttonStatistics.Name = "buttonStatistics";
            this.buttonStatistics.Size = new System.Drawing.Size(215, 119);
            this.buttonStatistics.TabIndex = 4;
            this.buttonStatistics.Text = "STATISTICS";
            this.buttonStatistics.UseVisualStyleBackColor = false;
            this.buttonStatistics.Click += new System.EventHandler(this.buttonStatistics_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.LemonChiffon;
            this.ClientSize = new System.Drawing.Size(1092, 655);
            this.Controls.Add(this.buttonStatistics);
            this.Controls.Add(this.buttonJoinRoom);
            this.Controls.Add(this.buttonCreateRoom);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.buttonClose);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Text = "Trivia-menu";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonClose;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button buttonCreateRoom;
        private System.Windows.Forms.Button buttonJoinRoom;
        private System.Windows.Forms.Button buttonStatistics;
    }
}