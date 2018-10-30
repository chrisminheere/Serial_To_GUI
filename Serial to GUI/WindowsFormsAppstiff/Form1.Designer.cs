namespace WindowsFormsAppstiff
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
            this.components = new System.ComponentModel.Container();
            this.ESPLora = new System.IO.Ports.SerialPort(this.components);
            this.resultsBox = new System.Windows.Forms.ListBox();
            this.SuspendLayout();
            // 
            // ESPLora
            // 
            this.ESPLora.BaudRate = 115200;
            this.ESPLora.PortName = "COM3";
            this.ESPLora.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.ESPLora_DataReceived);
            // 
            // resultsBox
            // 
            this.resultsBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.resultsBox.FormattingEnabled = true;
            this.resultsBox.Location = new System.Drawing.Point(8, 8);
            this.resultsBox.Name = "resultsBox";
            this.resultsBox.Size = new System.Drawing.Size(712, 325);
            this.resultsBox.TabIndex = 0;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(728, 341);
            this.Controls.Add(this.resultsBox);
            this.Name = "Form1";
            this.Padding = new System.Windows.Forms.Padding(8);
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.IO.Ports.SerialPort ESPLora;
        private System.Windows.Forms.ListBox resultsBox;
    }
}

