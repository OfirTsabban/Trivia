namespace GUI
{
    partial class JoinRoom
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(JoinRoom));
            this.listViewRooms = new System.Windows.Forms.ListView();
            this.label1 = new System.Windows.Forms.Label();
            this.buttonNext = new System.Windows.Forms.Button();
            this.buttonRefresh = new System.Windows.Forms.Button();
            this.buttonBack = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // listViewRooms
            // 
            this.listViewRooms.Alignment = System.Windows.Forms.ListViewAlignment.Left;
            this.listViewRooms.BackColor = System.Drawing.Color.FloralWhite;
            this.listViewRooms.Font = new System.Drawing.Font("Showcard Gothic", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.listViewRooms.ForeColor = System.Drawing.Color.DarkRed;
            this.listViewRooms.HideSelection = false;
            this.listViewRooms.Location = new System.Drawing.Point(68, 187);
            this.listViewRooms.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.listViewRooms.Name = "listViewRooms";
            this.listViewRooms.Size = new System.Drawing.Size(1193, 337);
            this.listViewRooms.TabIndex = 0;
            this.listViewRooms.UseCompatibleStateImageBehavior = false;
            this.listViewRooms.View = System.Windows.Forms.View.List;
            this.listViewRooms.SelectedIndexChanged += new System.EventHandler(this.listViewRooms_SelectedIndexChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Showcard Gothic", 48F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(431, 44);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(464, 98);
            this.label1.TabIndex = 1;
            this.label1.Text = "JOIN ROOM";
            // 
            // buttonNext
            // 
            this.buttonNext.AutoSize = true;
            this.buttonNext.BackColor = System.Drawing.Color.FloralWhite;
            this.buttonNext.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonNext.Location = new System.Drawing.Point(821, 579);
            this.buttonNext.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.buttonNext.Name = "buttonNext";
            this.buttonNext.Size = new System.Drawing.Size(196, 100);
            this.buttonNext.TabIndex = 3;
            this.buttonNext.Text = "NEXT";
            this.buttonNext.UseVisualStyleBackColor = false;
            this.buttonNext.Click += new System.EventHandler(this.buttonNext_Click);
            // 
            // buttonRefresh
            // 
            this.buttonRefresh.AutoSize = true;
            this.buttonRefresh.BackColor = System.Drawing.Color.FloralWhite;
            this.buttonRefresh.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonRefresh.Location = new System.Drawing.Point(529, 579);
            this.buttonRefresh.Name = "buttonRefresh";
            this.buttonRefresh.Size = new System.Drawing.Size(190, 100);
            this.buttonRefresh.TabIndex = 4;
            this.buttonRefresh.Text = "REFRESH";
            this.buttonRefresh.UseVisualStyleBackColor = false;
            this.buttonRefresh.Click += new System.EventHandler(this.buttonRefresh_Click);
            // 
            // buttonBack
            // 
            this.buttonBack.BackColor = System.Drawing.Color.FloralWhite;
            this.buttonBack.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonBack.Location = new System.Drawing.Point(229, 579);
            this.buttonBack.Name = "buttonBack";
            this.buttonBack.Size = new System.Drawing.Size(190, 100);
            this.buttonBack.TabIndex = 5;
            this.buttonBack.Text = "BACK";
            this.buttonBack.UseVisualStyleBackColor = false;
            this.buttonBack.Click += new System.EventHandler(this.buttonBack_Click);
            // 
            // JoinRoom
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.BackColor = System.Drawing.Color.LemonChiffon;
            this.ClientSize = new System.Drawing.Size(1322, 713);
            this.Controls.Add(this.buttonBack);
            this.Controls.Add(this.buttonRefresh);
            this.Controls.Add(this.buttonNext);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.listViewRooms);
            this.ForeColor = System.Drawing.Color.DarkRed;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.Name = "JoinRoom";
            this.RightToLeftLayout = true;
            this.Text = "Trivia-join room";
            this.Load += new System.EventHandler(this.JoinRoom_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button buttonNext;
        private System.Windows.Forms.Button buttonRefresh;
        private System.Windows.Forms.ListView listViewRooms;
        private System.Windows.Forms.Button buttonBack;
    }
}