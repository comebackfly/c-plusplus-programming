using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WatchingEyes
{
    public partial class Form1 : Form
    {
        private Eye leftEye;
        private Eye rightEye;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //create eyes with pupils
            int eyeSize = 70;
            int pupilSize=10;
            Pupil leftPupil = new Pupil();
            leftEye = new Eye(((this.Width / 2) - eyeSize), ((this.Height / 2) - (eyeSize / 2)), eyeSize, leftPupil);
            leftPupil.setPupil(leftEye.getPositionX()+pupilSize/2, leftEye.getPositionY()+pupilSize/2, pupilSize);

            Pupil rightPupil = new Pupil();
            rightEye = new Eye(((this.Width / 2)), ((this.Height / 2) - (eyeSize / 2)), eyeSize, rightPupil);
            rightPupil.setPupil(rightEye.getPositionX()+pupilSize/2, rightEye.getPositionY()+pupilSize/2, pupilSize);
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            label.Text = e.X.ToString() + ", " + e.Y.ToString();

            if(e.X<=leftEye.getPositionX()+leftEye.getWidth() && e.X>=leftEye.getPositionX()&&e.Y<=leftEye.getPositionY()+leftEye.getWidth()&&e.Y>=leftEye.getPositionY()){
                leftEye.getPupil().updatePupil(e.X, e.Y);
            }
            else if (e.X <= rightEye.getPositionX() + rightEye.getWidth() && e.X >= rightEye.getPositionX() && e.Y <= rightEye.getPositionY() + rightEye.getWidth() && e.Y >= rightEye.getPositionY())
            {
                rightEye.getPupil().updatePupil(e.X, e.Y);
            }
        }

        private void Form1_MouseLeave(object sender, EventArgs e)
        {
            label.Text = "mouse leaving the window";
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            // Get Graphics Object
            Graphics g = e.Graphics;
            leftEye.paintEye(g);
            rightEye.paintEye(g);
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {

            switch(e.Button){

                case MouseButtons.Left: leftEye.close();
                    break;

                case MouseButtons.Right: rightEye.close();
                    break;
            }

        }
    }
}
