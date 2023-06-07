﻿namespace GUI
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
            this.buttonRoomInfo = new System.Windows.Forms.Button();
            this.buttonNext = new System.Windows.Forms.Button();
            this.buttonRefresh = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // listViewRooms
            // 
            this.listViewRooms.BackColor = System.Drawing.Color.FloralWhite;
            this.listViewRooms.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.listViewRooms.ForeColor = System.Drawing.Color.DarkRed;
            this.listViewRooms.HideSelection = false;
            this.listViewRooms.Location = new System.Drawing.Point(67, 139);
            this.listViewRooms.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.listViewRooms.Name = "listViewRooms";
            this.listViewRooms.Size = new System.Drawing.Size(631, 182);
            this.listViewRooms.TabIndex = 0;
            this.listViewRooms.UseCompatibleStateImageBehavior = false;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Showcard Gothic", 48F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(161, 30);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(464, 98);
            this.label1.TabIndex = 1;
            this.label1.Text = "JOIN ROOM";
            // 
            // buttonRoomInfo
            // 
            this.buttonRoomInfo.BackColor = System.Drawing.Color.FloralWhite;
            this.buttonRoomInfo.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonRoomInfo.Location = new System.Drawing.Point(106, 354);
            this.buttonRoomInfo.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.buttonRoomInfo.Name = "buttonRoomInfo";
            this.buttonRoomInfo.Size = new System.Drawing.Size(159, 64);
            this.buttonRoomInfo.TabIndex = 2;
            this.buttonRoomInfo.Text = "ROOM INFO";
            this.buttonRoomInfo.UseVisualStyleBackColor = false;
            this.buttonRoomInfo.Click += new System.EventHandler(this.buttonRoomInfo_Click);
            // 
            // buttonNext
            // 
            this.buttonNext.BackColor = System.Drawing.Color.FloralWhite;
            this.buttonNext.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonNext.Location = new System.Drawing.Point(518, 353);
            this.buttonNext.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.buttonNext.Name = "buttonNext";
            this.buttonNext.Size = new System.Drawing.Size(159, 64);
            this.buttonNext.TabIndex = 3;
            this.buttonNext.Text = "NEXT";
            this.buttonNext.UseVisualStyleBackColor = false;
            this.buttonNext.Click += new System.EventHandler(this.buttonNext_Click);
            // 
            // buttonRefresh
            // 
            this.buttonRefresh.BackColor = System.Drawing.Color.FloralWhite;
            this.buttonRefresh.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonRefresh.Location = new System.Drawing.Point(315, 353);
            this.buttonRefresh.Name = "buttonRefresh";
            this.buttonRefresh.Size = new System.Drawing.Size(144, 64);
            this.buttonRefresh.TabIndex = 4;
            this.buttonRefresh.Text = "REFRESH";
            this.buttonRefresh.UseVisualStyleBackColor = false;
            this.buttonRefresh.Click += new System.EventHandler(this.buttonRefresh_Click);
            // 
            // JoinRoom
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.LemonChiffon;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.buttonRefresh);
            this.Controls.Add(this.buttonNext);
            this.Controls.Add(this.buttonRoomInfo);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.listViewRooms);
            this.ForeColor = System.Drawing.Color.DarkRed;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.Name = "JoinRoom";
            this.Text = "Trivia-join room";
            this.Load += new System.EventHandler(this.JoinRoom_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListView listViewRooms;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button buttonRoomInfo;
        private System.Windows.Forms.Button buttonNext;
        private System.Windows.Forms.Button buttonRefresh;
    }
}