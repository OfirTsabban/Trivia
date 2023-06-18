namespace GUI
{
    partial class Question
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
            this.components = new System.ComponentModel.Container();
            this.label1 = new System.Windows.Forms.Label();
            this.labelQuestion = new System.Windows.Forms.Label();
            this.buttonAnswer1 = new System.Windows.Forms.Button();
            this.buttonAnswer2 = new System.Windows.Forms.Button();
            this.buttonAnswer3 = new System.Windows.Forms.Button();
            this.buttonAnswer4 = new System.Windows.Forms.Button();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.label3 = new System.Windows.Forms.Label();
            this.labelCorresctAnswer = new System.Windows.Forms.Label();
            this.labelTime = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.labelQuestionsLeft = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Showcard Gothic", 48F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(504, 22);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(310, 98);
            this.label1.TabIndex = 0;
            this.label1.Text = "TRIVIA";
            // 
            // labelQuestion
            // 
            this.labelQuestion.AutoSize = true;
            this.labelQuestion.Font = new System.Drawing.Font("Showcard Gothic", 22.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelQuestion.Location = new System.Drawing.Point(300, 214);
            this.labelQuestion.Name = "labelQuestion";
            this.labelQuestion.Size = new System.Drawing.Size(198, 46);
            this.labelQuestion.TabIndex = 1;
            this.labelQuestion.Text = "question";
            // 
            // buttonAnswer1
            // 
            this.buttonAnswer1.BackColor = System.Drawing.Color.FloralWhite;
            this.buttonAnswer1.Font = new System.Drawing.Font("Showcard Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonAnswer1.Location = new System.Drawing.Point(289, 294);
            this.buttonAnswer1.Name = "buttonAnswer1";
            this.buttonAnswer1.Size = new System.Drawing.Size(757, 78);
            this.buttonAnswer1.TabIndex = 2;
            this.buttonAnswer1.Text = "answer1";
            this.buttonAnswer1.UseVisualStyleBackColor = false;
            this.buttonAnswer1.Click += new System.EventHandler(this.buttonAnswer1_Click);
            // 
            // buttonAnswer2
            // 
            this.buttonAnswer2.BackColor = System.Drawing.Color.FloralWhite;
            this.buttonAnswer2.Font = new System.Drawing.Font("Showcard Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonAnswer2.Location = new System.Drawing.Point(289, 393);
            this.buttonAnswer2.Name = "buttonAnswer2";
            this.buttonAnswer2.Size = new System.Drawing.Size(757, 78);
            this.buttonAnswer2.TabIndex = 3;
            this.buttonAnswer2.Text = "ANSWER2";
            this.buttonAnswer2.UseVisualStyleBackColor = false;
            // 
            // buttonAnswer3
            // 
            this.buttonAnswer3.BackColor = System.Drawing.Color.FloralWhite;
            this.buttonAnswer3.Font = new System.Drawing.Font("Showcard Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonAnswer3.Location = new System.Drawing.Point(289, 490);
            this.buttonAnswer3.Name = "buttonAnswer3";
            this.buttonAnswer3.Size = new System.Drawing.Size(757, 78);
            this.buttonAnswer3.TabIndex = 4;
            this.buttonAnswer3.Text = "ANSWER3";
            this.buttonAnswer3.UseVisualStyleBackColor = false;
            // 
            // buttonAnswer4
            // 
            this.buttonAnswer4.BackColor = System.Drawing.Color.FloralWhite;
            this.buttonAnswer4.Font = new System.Drawing.Font("Showcard Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonAnswer4.Location = new System.Drawing.Point(289, 597);
            this.buttonAnswer4.Name = "buttonAnswer4";
            this.buttonAnswer4.Size = new System.Drawing.Size(757, 78);
            this.buttonAnswer4.TabIndex = 5;
            this.buttonAnswer4.Text = "ANSWER4";
            this.buttonAnswer4.UseVisualStyleBackColor = false;
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(938, 38);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(240, 29);
            this.label3.TabIndex = 7;
            this.label3.Text = "correct answers: ";
            // 
            // labelCorresctAnswer
            // 
            this.labelCorresctAnswer.AutoSize = true;
            this.labelCorresctAnswer.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelCorresctAnswer.Location = new System.Drawing.Point(1184, 38);
            this.labelCorresctAnswer.Name = "labelCorresctAnswer";
            this.labelCorresctAnswer.Size = new System.Drawing.Size(27, 29);
            this.labelCorresctAnswer.TabIndex = 8;
            this.labelCorresctAnswer.Text = "0";
            this.labelCorresctAnswer.Click += new System.EventHandler(this.labelCorresctAnswer_Click);
            // 
            // labelTime
            // 
            this.labelTime.AutoSize = true;
            this.labelTime.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelTime.Location = new System.Drawing.Point(27, 38);
            this.labelTime.Name = "labelTime";
            this.labelTime.Size = new System.Drawing.Size(41, 29);
            this.labelTime.TabIndex = 9;
            this.labelTime.Text = "00";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.Location = new System.Drawing.Point(938, 91);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(201, 29);
            this.label6.TabIndex = 10;
            this.label6.Text = "QUESTIONS LEFT:";
            // 
            // labelQuestionsLeft
            // 
            this.labelQuestionsLeft.AutoSize = true;
            this.labelQuestionsLeft.Font = new System.Drawing.Font("Showcard Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelQuestionsLeft.Location = new System.Drawing.Point(1184, 91);
            this.labelQuestionsLeft.Name = "labelQuestionsLeft";
            this.labelQuestionsLeft.Size = new System.Drawing.Size(27, 29);
            this.labelQuestionsLeft.TabIndex = 11;
            this.labelQuestionsLeft.Text = "0";
            // 
            // Question
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.LemonChiffon;
            this.ClientSize = new System.Drawing.Size(1303, 809);
            this.Controls.Add(this.labelQuestionsLeft);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.labelTime);
            this.Controls.Add(this.labelCorresctAnswer);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.buttonAnswer4);
            this.Controls.Add(this.buttonAnswer3);
            this.Controls.Add(this.buttonAnswer2);
            this.Controls.Add(this.buttonAnswer1);
            this.Controls.Add(this.labelQuestion);
            this.Controls.Add(this.label1);
            this.ForeColor = System.Drawing.Color.DarkRed;
            this.Name = "Question";
            this.Text = "Trivia-question";
            this.Load += new System.EventHandler(this.Question_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label labelQuestion;
        private System.Windows.Forms.Button buttonAnswer1;
        private System.Windows.Forms.Button buttonAnswer2;
        private System.Windows.Forms.Button buttonAnswer3;
        private System.Windows.Forms.Button buttonAnswer4;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label labelCorresctAnswer;
        private System.Windows.Forms.Label labelTime;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label labelQuestionsLeft;
    }
}