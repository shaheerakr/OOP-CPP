using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class calculator : Form
    {
        double temp = 0;
        string opration = "";
        bool flag = false;
        public calculator()
        {
            InitializeComponent();
        }

        private void value_Click(object sender, EventArgs e)
        {
            if ((result.Text == "0") || (flag))
            {
                result.Clear();
                flag = false;
            }
            Button value = (Button)sender;
            result.Text = result.Text + value.Text;
        }

        private void valueCE_Click(object sender, EventArgs e)
        {
            result.Text = "0";
        }

        private void opration_Click(object sender, EventArgs e)
        {
            Button value = (Button)sender;
            temp = double.Parse(result.Text);
            opration = value.Text;
            flag = true;
        }

        private void valueEqual_Click(object sender, EventArgs e)
        {
            switch (opration)
            {
                case "+":
                    result.Text = Convert.ToString(temp + double.Parse(result.Text));
                    break;
                case "-":
                    result.Text = Convert.ToString(temp - double.Parse(result.Text));
                    break;
                case "*":
                    result.Text = Convert.ToString(temp * double.Parse(result.Text));
                    break;
                case "/":
                    result.Text = Convert.ToString(temp / double.Parse(result.Text));
                    break;
                default:
                    break;
            }
        }
    }
}
