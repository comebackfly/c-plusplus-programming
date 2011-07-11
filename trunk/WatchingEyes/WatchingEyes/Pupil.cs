using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;
using System.Windows.Forms;

namespace WatchingEyes
{
    class Pupil
    {
        private int positionX;
        private int positionY;
        private int size;
        private Graphics g;
        private SolidBrush pupilBrush;

        public Pupil(int positionX, int positionY, int size)
        {
            this.size = size;
            this.positionX = positionX;
            this.positionY = positionY;
            pupilBrush = new SolidBrush(Color.Blue);
        }

        public void paintPupil(Graphics g, int clientWidth, int clientHeight){
            this.g = g;
            // Create a new pen that we shall use for drawing the line
               g.FillEllipse(pupilBrush, clientWidth, clientHeight, this.size, this.size);
        }

        public void updatePupil(Graphics g, int positionX, int positionY)
        {
            //draw where the mouse pointer is present
            g.FillEllipse(pupilBrush, positionX, positionY, this.size, this.size);
            //graphics.Dispose();

            //{
            //    g.FillEllipse(pupilBrush, this.positionX, this.positionY, this.size, this.size);
            //}
            //else
            //{
                //MessageBox.Show("" + positionX + " " + positionY + " " + this.size);
          
        }

        public void setUnvisible()
        {
            SolidBrush invisible = new SolidBrush(Color.Teal);
            g.FillEllipse(invisible, this.positionX, this.positionY, this.size, this.size);
        }
    }
}
