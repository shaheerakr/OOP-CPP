namespace WindowsFormsApp1
{
    partial class calculator
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
            this.value1 = new System.Windows.Forms.Button();
            this.value2 = new System.Windows.Forms.Button();
            this.value3 = new System.Windows.Forms.Button();
            this.value0 = new System.Windows.Forms.Button();
            this.valueEqual = new System.Windows.Forms.Button();
            this.valueDec = new System.Windows.Forms.Button();
            this.value00 = new System.Windows.Forms.Button();
            this.valueAdd = new System.Windows.Forms.Button();
            this.value4 = new System.Windows.Forms.Button();
            this.value5 = new System.Windows.Forms.Button();
            this.value6 = new System.Windows.Forms.Button();
            this.valueSub = new System.Windows.Forms.Button();
            this.value7 = new System.Windows.Forms.Button();
            this.value8 = new System.Windows.Forms.Button();
            this.value9 = new System.Windows.Forms.Button();
            this.valueProd = new System.Windows.Forms.Button();
            this.valueCE = new System.Windows.Forms.Button();
            this.valueC = new System.Windows.Forms.Button();
            this.valueX = new System.Windows.Forms.Button();
            this.valueDiv = new System.Windows.Forms.Button();
            this.result = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // value1
            // 
            this.value1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.value1.Location = new System.Drawing.Point(10, 146);
            this.value1.Name = "value1";
            this.value1.Size = new System.Drawing.Size(57, 28);
            this.value1.TabIndex = 1;
            this.value1.Text = "1";
            this.value1.UseVisualStyleBackColor = true;
            this.value1.Click += new System.EventHandler(this.value_Click);
            // 
            // value2
            // 
            this.value2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.value2.Location = new System.Drawing.Point(73, 146);
            this.value2.Name = "value2";
            this.value2.Size = new System.Drawing.Size(57, 28);
            this.value2.TabIndex = 2;
            this.value2.Text = "2";
            this.value2.UseVisualStyleBackColor = true;
            this.value2.Click += new System.EventHandler(this.value_Click);
            // 
            // value3
            // 
            this.value3.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.value3.Location = new System.Drawing.Point(136, 146);
            this.value3.Name = "value3";
            this.value3.Size = new System.Drawing.Size(57, 28);
            this.value3.TabIndex = 3;
            this.value3.Text = "3";
            this.value3.UseVisualStyleBackColor = true;
            this.value3.Click += new System.EventHandler(this.value_Click);
            // 
            // value0
            // 
            this.value0.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.value0.Location = new System.Drawing.Point(73, 180);
            this.value0.Name = "value0";
            this.value0.Size = new System.Drawing.Size(57, 28);
            this.value0.TabIndex = 4;
            this.value0.Text = "0";
            this.value0.UseVisualStyleBackColor = true;
            this.value0.Click += new System.EventHandler(this.value_Click);
            // 
            // valueEqual
            // 
            this.valueEqual.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.valueEqual.Location = new System.Drawing.Point(199, 180);
            this.valueEqual.Name = "valueEqual";
            this.valueEqual.Size = new System.Drawing.Size(57, 28);
            this.valueEqual.TabIndex = 5;
            this.valueEqual.Text = "=";
            this.valueEqual.UseVisualStyleBackColor = true;
            this.valueEqual.Click += new System.EventHandler(this.valueEqual_Click);
            // 
            // valueDec
            // 
            this.valueDec.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.valueDec.Location = new System.Drawing.Point(136, 180);
            this.valueDec.Name = "valueDec";
            this.valueDec.Size = new System.Drawing.Size(57, 28);
            this.valueDec.TabIndex = 6;
            this.valueDec.Text = ".";
            this.valueDec.UseVisualStyleBackColor = true;
            this.valueDec.Click += new System.EventHandler(this.value_Click);
            // 
            // value00
            // 
            this.value00.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.value00.Location = new System.Drawing.Point(10, 180);
            this.value00.Name = "value00";
            this.value00.Size = new System.Drawing.Size(57, 28);
            this.value00.TabIndex = 7;
            this.value00.Text = "00";
            this.value00.UseVisualStyleBackColor = true;
            this.value00.Click += new System.EventHandler(this.value_Click);
            // 
            // valueAdd
            // 
            this.valueAdd.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.valueAdd.Location = new System.Drawing.Point(199, 146);
            this.valueAdd.Name = "valueAdd";
            this.valueAdd.Size = new System.Drawing.Size(57, 28);
            this.valueAdd.TabIndex = 8;
            this.valueAdd.Text = "+";
            this.valueAdd.UseVisualStyleBackColor = true;
            this.valueAdd.Click += new System.EventHandler(this.opration_Click);
            // 
            // value4
            // 
            this.value4.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.value4.Location = new System.Drawing.Point(10, 112);
            this.value4.Name = "value4";
            this.value4.Size = new System.Drawing.Size(57, 28);
            this.value4.TabIndex = 9;
            this.value4.Text = "4";
            this.value4.UseVisualStyleBackColor = true;
            this.value4.Click += new System.EventHandler(this.value_Click);
            // 
            // value5
            // 
            this.value5.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.value5.Location = new System.Drawing.Point(73, 112);
            this.value5.Name = "value5";
            this.value5.Size = new System.Drawing.Size(57, 28);
            this.value5.TabIndex = 10;
            this.value5.Text = "5";
            this.value5.UseVisualStyleBackColor = true;
            this.value5.Click += new System.EventHandler(this.value_Click);
            // 
            // value6
            // 
            this.value6.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.value6.Location = new System.Drawing.Point(136, 112);
            this.value6.Name = "value6";
            this.value6.Size = new System.Drawing.Size(57, 28);
            this.value6.TabIndex = 11;
            this.value6.Text = "6";
            this.value6.UseVisualStyleBackColor = true;
            this.value6.Click += new System.EventHandler(this.value_Click);
            // 
            // valueSub
            // 
            this.valueSub.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.valueSub.Location = new System.Drawing.Point(199, 112);
            this.valueSub.Name = "valueSub";
            this.valueSub.Size = new System.Drawing.Size(57, 28);
            this.valueSub.TabIndex = 12;
            this.valueSub.Text = "-";
            this.valueSub.UseVisualStyleBackColor = true;
            this.valueSub.Click += new System.EventHandler(this.opration_Click);
            // 
            // value7
            // 
            this.value7.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.value7.Location = new System.Drawing.Point(10, 78);
            this.value7.Name = "value7";
            this.value7.Size = new System.Drawing.Size(57, 28);
            this.value7.TabIndex = 13;
            this.value7.Text = "7";
            this.value7.UseVisualStyleBackColor = true;
            this.value7.Click += new System.EventHandler(this.value_Click);
            // 
            // value8
            // 
            this.value8.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.value8.Location = new System.Drawing.Point(73, 78);
            this.value8.Name = "value8";
            this.value8.Size = new System.Drawing.Size(57, 28);
            this.value8.TabIndex = 14;
            this.value8.Text = "8";
            this.value8.UseVisualStyleBackColor = true;
            this.value8.Click += new System.EventHandler(this.value_Click);
            // 
            // value9
            // 
            this.value9.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.value9.Location = new System.Drawing.Point(136, 78);
            this.value9.Name = "value9";
            this.value9.Size = new System.Drawing.Size(57, 28);
            this.value9.TabIndex = 15;
            this.value9.Text = "9";
            this.value9.UseVisualStyleBackColor = true;
            this.value9.Click += new System.EventHandler(this.value_Click);
            // 
            // valueProd
            // 
            this.valueProd.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.valueProd.Location = new System.Drawing.Point(199, 78);
            this.valueProd.Name = "valueProd";
            this.valueProd.Size = new System.Drawing.Size(57, 28);
            this.valueProd.TabIndex = 16;
            this.valueProd.Text = "*";
            this.valueProd.UseVisualStyleBackColor = true;
            this.valueProd.Click += new System.EventHandler(this.opration_Click);
            // 
            // valueCE
            // 
            this.valueCE.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.valueCE.Location = new System.Drawing.Point(10, 44);
            this.valueCE.Name = "valueCE";
            this.valueCE.Size = new System.Drawing.Size(57, 28);
            this.valueCE.TabIndex = 17;
            this.valueCE.Text = "CE";
            this.valueCE.UseVisualStyleBackColor = true;
            this.valueCE.Click += new System.EventHandler(this.valueCE_Click);
            // 
            // valueC
            // 
            this.valueC.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.valueC.Location = new System.Drawing.Point(73, 44);
            this.valueC.Name = "valueC";
            this.valueC.Size = new System.Drawing.Size(57, 28);
            this.valueC.TabIndex = 18;
            this.valueC.Text = "C";
            this.valueC.UseVisualStyleBackColor = true;
            // 
            // valueX
            // 
            this.valueX.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.valueX.Location = new System.Drawing.Point(136, 44);
            this.valueX.Name = "valueX";
            this.valueX.Size = new System.Drawing.Size(57, 28);
            this.valueX.TabIndex = 19;
            this.valueX.Text = "X";
            this.valueX.UseVisualStyleBackColor = true;
            // 
            // valueDiv
            // 
            this.valueDiv.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.valueDiv.Location = new System.Drawing.Point(199, 44);
            this.valueDiv.Name = "valueDiv";
            this.valueDiv.Size = new System.Drawing.Size(57, 28);
            this.valueDiv.TabIndex = 20;
            this.valueDiv.Text = "/";
            this.valueDiv.UseVisualStyleBackColor = true;
            this.valueDiv.Click += new System.EventHandler(this.opration_Click);
            // 
            // result
            // 
            this.result.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.5F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.result.Location = new System.Drawing.Point(10, 12);
            this.result.Name = "result";
            this.result.Size = new System.Drawing.Size(246, 23);
            this.result.TabIndex = 21;
            this.result.Text = "0";
            this.result.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // calculator
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(268, 223);
            this.Controls.Add(this.result);
            this.Controls.Add(this.valueDiv);
            this.Controls.Add(this.valueX);
            this.Controls.Add(this.valueC);
            this.Controls.Add(this.valueCE);
            this.Controls.Add(this.valueProd);
            this.Controls.Add(this.value9);
            this.Controls.Add(this.value8);
            this.Controls.Add(this.value7);
            this.Controls.Add(this.valueSub);
            this.Controls.Add(this.value6);
            this.Controls.Add(this.value5);
            this.Controls.Add(this.value4);
            this.Controls.Add(this.valueAdd);
            this.Controls.Add(this.value00);
            this.Controls.Add(this.valueDec);
            this.Controls.Add(this.valueEqual);
            this.Controls.Add(this.value0);
            this.Controls.Add(this.value3);
            this.Controls.Add(this.value2);
            this.Controls.Add(this.value1);
            this.Name = "calculator";
            this.Text = "Calculator";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button value1;
        private System.Windows.Forms.Button value2;
        private System.Windows.Forms.Button value3;
        private System.Windows.Forms.Button value0;
        private System.Windows.Forms.Button valueEqual;
        private System.Windows.Forms.Button valueDec;
        private System.Windows.Forms.Button value00;
        private System.Windows.Forms.Button valueAdd;
        private System.Windows.Forms.Button value4;
        private System.Windows.Forms.Button value5;
        private System.Windows.Forms.Button value6;
        private System.Windows.Forms.Button valueSub;
        private System.Windows.Forms.Button value7;
        private System.Windows.Forms.Button value8;
        private System.Windows.Forms.Button value9;
        private System.Windows.Forms.Button valueProd;
        private System.Windows.Forms.Button valueCE;
        private System.Windows.Forms.Button valueC;
        private System.Windows.Forms.Button valueX;
        private System.Windows.Forms.Button valueDiv;
        private System.Windows.Forms.TextBox result;
    }
}

