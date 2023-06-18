namespace GUI
{
    partial class EndGame
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
            this.listView1 = new System.Windows.Forms.ListView();
            this.label1 = new System.Windows.Forms.Label();
            this.labelCorrectAnswers = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.labelTime = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.labelName = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // listView1
            // 
            this.listView1.HideSelection = false;
            this.listView1.Location = new System.Drawing.Point(40, 155);
            this.listView1.Name = "listView1";
            this.listView1.Size = new System.Drawing.Size(1051, 300);
            this.listView1.TabIndex = 0;
            this.listView1.UseCompatibleStateImageBehavior = false;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Showcard Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(68, 487);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(285, 35);
            this.label1.TabIndex = 1;
            this.label1.Text = "correct answers:";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // labelCorrectAnswers
            // 
            this.labelCorrectAnswers.AutoSize = true;
            this.labelCorrectAnswers.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelCorrectAnswers.Location = new System.Drawing.Point(359, 491);
            this.labelCorrectAnswers.Name = "labelCorrectAnswers";
            this.labelCorrectAnswers.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.labelCorrectAnswers.Size = new System.Drawing.Size(106, 29);
            this.labelCorrectAnswers.TabIndex = 2;
            this.labelCorrectAnswers.Text = "number";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Showcard Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(68, 537);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(342, 35);
            this.label3.TabIndex = 3;
            this.label3.Text = "AVERAGE ANSWER TIME:";
            // 
            // labelTime
            // 
            this.labelTime.AutoSize = true;
            this.labelTime.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelTime.Location = new System.Drawing.Point(416, 543);
            this.labelTime.Name = "labelTime";
            this.labelTime.Size = new System.Drawing.Size(67, 29);
            this.labelTime.TabIndex = 4;
            this.labelTime.Text = "TIME";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Showcard Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(68, 584);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(139, 35);
            this.label5.TabIndex = 5;
            this.label5.Text = "WINNER:";
            // 
            // labelName
            // 
            this.labelName.AutoSize = true;
            this.labelName.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelName.Location = new System.Drawing.Point(213, 588);
            this.labelName.Name = "labelName";
            this.labelName.Size = new System.Drawing.Size(73, 29);
            this.labelName.TabIndex = 6;
            this.labelName.Text = "NAME";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Showcard Gothic", 36F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(373, 46);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(317, 74);
            this.label2.TabIndex = 7;
            this.label2.Text = "END GAME";
            // 
            // EndGame
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.LemonChiffon;
            this.ClientSize = new System.Drawing.Size(1120, 676);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.labelName);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.labelTime);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.labelCorrectAnswers);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.listView1);
            this.ForeColor = System.Drawing.Color.DarkRed;
            this.Name = "EndGame";
            this.Text = "Trivia-end game";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListView listView1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label labelCorrectAnswers;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label labelTime;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label labelName;
        private System.Windows.Forms.Label label2;
    }
}