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
        private int eyeSize;
        private int pupilSize;
        private int mouseX = 0;
        private int mouseY = 0;
        private float x;
        private float y;
        private Boolean rightPupilClosed = true;
        private Boolean leftPupilClosed = true;


        public Form1()
        {
            InitializeComponent();
            ResizeRedraw = true;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //create eyes with pupils
            eyeSize = 70;
            pupilSize = 10;

            leftEye = new Eye((ClientRectangle.Width / 2) - eyeSize, ClientRectangle.Height / 2, eyeSize);
            Pupil leftPupil = new Pupil(leftEye.getPositionX() + pupilSize / 2, leftEye.getPositionY() + pupilSize / 2, pupilSize);
            leftEye.setPupil(leftPupil);

            rightEye = new Eye((ClientRectangle.Width / 2), ClientRectangle.Height / 2, eyeSize);
            Pupil rightPupil = new Pupil(rightEye.getPositionX() + pupilSize / 2, rightEye.getPositionY() + pupilSize / 2, pupilSize);
            rightEye.setPupil(rightPupil);
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            mouseX = e.X;
            mouseY = e.Y;
            label.Text = "x: "+x.ToString() + ", y: " + y.ToString();

            Invalidate();
        }

        private void Form1_MouseLeave(object sender, EventArgs e)
        {
            label.Text = "mouse leaving the window ";
            Graphics graphics = CreateGraphics();
            leftEye.close(graphics);
            rightEye.close(graphics);
        }

        protected override void OnPaintBackground(PaintEventArgs e)
        {
            base.OnPaintBackground(e);
            Graphics graphics = CreateGraphics();

            if (leftEye.isClosed())
            {
                leftEye.close(graphics);
            }

            if (rightEye.isClosed())
            {
                rightEye.close(graphics);
            }

            //calculate eye-movement
            float factor = eyeSize / 8;

            x = this.mouseX - (ClientRectangle.Width / 2);
            y = this.mouseY - (ClientRectangle.Height / 2);

            float distance = (int)Math.Sqrt((x) * (x) + (y) * (y));

            x /= distance;
            y /= distance;

            x *= factor;
            y *= factor;

            x += ClientRectangle.Width / 2;
            y += ClientRectangle.Height / 2;

            leftEye.paintEye(e.Graphics, (ClientRectangle.Width / 2) - eyeSize, ClientRectangle.Height / 2);
            rightEye.paintEye(e.Graphics, (ClientRectangle.Width / 2), ClientRectangle.Height / 2);

            leftEye.updatePupil(e.Graphics, x - (40), y + (12), leftPupilClosed);
            rightEye.updatePupil(e.Graphics, x + (40), y + (12), rightPupilClosed);
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            switch (e.Button)
            {
                case MouseButtons.Left:
                    if (leftEye.isClosed())
                    {
                        leftEye.setClosed(false);
                        leftPupilClosed = true;
                    }
                    else
                    {
                        leftPupilClosed = false;
                        leftEye.setClosed(true);
                    }
                    break;

                case MouseButtons.Right:
                    if (rightEye.isClosed())
                    {
                        rightPupilClosed = true;
                        rightEye.setClosed(false);
                    }
                    else
                    {
                        rightPupilClosed = false;
                        rightEye.setClosed(true);
                    }
                    break;
            }
        }

        //private void Form1_Resize(object sender, System.EventArgs e)
        //{
        //    control = (Control)sender;

        //    // Ensure the Form remains square (Height = Width).
        //    if (control.Size.Height != control.Size.Width)
        //    {
        //        control.Size = new Size(control.Size.Width, control.Size.Width);
        //    }

        //    Invalidate();
        //}
    }
}