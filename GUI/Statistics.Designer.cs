namespace GUI
{
    partial class Statistics
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Statistics));
            this.label1 = new System.Windows.Forms.Label();
            this.buttonPersonalStatistics = new System.Windows.Forms.Button();
            this.buttonTableRecord = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Showcard Gothic", 48F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(118, 20);
            this.label1.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(377, 79);
            this.label1.TabIndex = 0;
            this.label1.Text = "STATISTICS";
            // 
            // buttonPersonalStatistics
            // 
            this.buttonPersonalStatistics.BackColor = System.Drawing.Color.FloralWhite;
            this.buttonPersonalStatistics.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonPersonalStatistics.Location = new System.Drawing.Point(58, 159);
            this.buttonPersonalStatistics.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.buttonPersonalStatistics.Name = "buttonPersonalStatistics";
            this.buttonPersonalStatistics.Size = new System.Drawing.Size(223, 113);
            this.buttonPersonalStatistics.TabIndex = 1;
            this.buttonPersonalStatistics.Text = "PERSONAL STATISTICS";
            this.buttonPersonalStatistics.UseVisualStyleBackColor = false;
            this.buttonPersonalStatistics.Click += new System.EventHandler(this.buttonPersonalStatistics_Click);
            // 
            // buttonTableRecord
            // 
            this.buttonTableRecord.BackColor = System.Drawing.Color.FloralWhite;
            this.buttonTableRecord.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonTableRecord.Location = new System.Drawing.Point(297, 159);
            this.buttonTableRecord.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.buttonTableRecord.Name = "buttonTableRecord";
            this.buttonTableRecord.Size = new System.Drawing.Size(226, 113);
            this.buttonTableRecord.TabIndex = 2;
            this.buttonTableRecord.Text = "TABLE RECORD";
            this.buttonTableRecord.UseVisualStyleBackColor = false;
            this.buttonTableRecord.Click += new System.EventHandler(this.buttonTableRecord_Click);
            // 
            // Statistics
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.LemonChiffon;
            this.ClientSize = new System.Drawing.Size(600, 366);
            this.Controls.Add(this.buttonTableRecord);
            this.Controls.Add(this.buttonPersonalStatistics);
            this.Controls.Add(this.label1);
            this.ForeColor = System.Drawing.Color.DarkRed;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Name = "Statistics";
            this.Text = "Trivia-statistics";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button buttonPersonalStatistics;
        private System.Windows.Forms.Button buttonTableRecord;
    }
}