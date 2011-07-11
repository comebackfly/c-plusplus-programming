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
        private Control control;
        private Graphics graphics;
        private int eyeSize;

        public Form1()
        {
            InitializeComponent();
            ResizeRedraw = true;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //create eyes with pupils
            eyeSize = 70;
            int pupilSize = 10;
            
            leftEye = new Eye((ClientRectangle.Width/2)-eyeSize, ClientRectangle.Height/2, eyeSize);
            Pupil leftPupil = new Pupil(leftEye.getPositionX() + pupilSize / 2, leftEye.getPositionY() + pupilSize / 2, pupilSize);
            leftEye.setPupil(leftPupil);

            
            rightEye = new Eye((ClientRectangle.Width / 2), ClientRectangle.Height / 2, eyeSize);
            Pupil rightPupil = new Pupil(rightEye.getPositionX() + pupilSize / 2, rightEye.getPositionY() + pupilSize / 2, pupilSize);
            rightEye.setPupil(rightPupil);

            //this.graphics = CreateGraphics();
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {

            

            //Point pt = Cursor.Position; // Get the mouse cursor in screen coordinates

            //Graphics graphics = CreateGraphics();
            label.Text = e.X.ToString() + ", " + e.Y.ToString();

            //this.graphics.FillEllipse(new SolidBrush(Color.BlueViolet), pt.X-10, pt.Y-10, 4, 4);

            //this.graphics.Dispose();

            //if(e.X<=leftEye.getPositionX()+leftEye.getWidth() && e.X>=leftEye.getPositionX()&&e.Y<=leftEye.getPositionY()+leftEye.getWidth()&&e.Y>=leftEye.getPositionY()){
            //leftEye.getPupil().updatePupil(this.graphics, e.X, e.Y);
            //}
            //else if (e.X <= rightEye.getPositionX() + rightEye.getWidth() && e.X >= rightEye.getPositionX() && e.Y <= rightEye.getPositionY() + rightEye.getWidth() && e.Y >= rightEye.getPositionY())
            //{
            //rightEye.getPupil().updatePupil(e.X, e.Y);
            //}

            Invalidate();
        }

        private void Form1_MouseLeave(object sender, EventArgs e)
        {
            label.Text = "mouse leaving the window";

            leftEye.close();
            rightEye.close();
        }

        //private void Form1_Paint(object sender, PaintEventArgs e)
        //{
        //    // Get Graphics Object
        //    Graphics g = e.Graphics;
        //    leftEye.paintEye(g);
        //    rightEye.paintEye(g);
        //}

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {

            switch (e.Button)
            {
                case MouseButtons.Left: leftEye.close();
                    break;

                case MouseButtons.Right: rightEye.close();
                    break;
            }

        }

        protected override void OnPaintBackground(PaintEventArgs e)
        {
            base.OnPaintBackground(e);

            leftEye.paintEye(e.Graphics, (ClientRectangle.Width / 2) - eyeSize, ClientRectangle.Height / 2);
            rightEye.paintEye(e.Graphics, (ClientRectangle.Width/2), ClientRectangle.Height/2);

            Point local = this.PointToClient(Cursor.Position);
            //e.Graphics.DrawEllipse(Pens.Red, local.X - 25, local.Y - 25, 20, 20);

            leftEye.updatePupil(e.Graphics, local.X-100, local.Y-100);

        }

        private void Form1_Resize(object sender, System.EventArgs e)
        {
            control = (Control)sender;

            // Ensure the Form remains square (Height = Width).
            if (control.Size.Height != control.Size.Width)
            {
                control.Size = new Size(control.Size.Width, control.Size.Width);
            }

            Invalidate();
            Console.WriteLine("Resize");
        }
    }
}