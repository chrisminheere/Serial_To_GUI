using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsAppstiff
{
    public partial class Form1 : Form
    {
        public Form1() => InitializeComponent();

        private void ESPLora_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            //Save text from lora
            String text = ESPLora.ReadLine();

            //Run this code on the UI thread
            this.Invoke(new MethodInvoker(delegate() 
            {
                //Add item to the list
                resultsBox.Items.Add(text);

                //Select the latest added item
                resultsBox.SelectedIndex = resultsBox.Items.Count - 1;
            }));
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //Open serial port
            ESPLora.Open();
        }

      
    }
}
