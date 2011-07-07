using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;
using System.Windows.Forms;

namespace WatchingEyes
{
    class Eye
    {

        private int positionX;
        private int positionY;
        private int size;
        private int status;
        private Pupil pupil;
        private Graphics g;

        public Eye(int positionX, int positionY, int size, Pupil pupil)
        {
            this.positionX = positionX;
            this.positionY = positionY;
            this.size=size;
            this.pupil = pupil;
        }

        public void paintEye(Graphics g)
        {
            this.g = g;
            // Create a new pen that we shall use for drawing the line
            Pen myPen = new Pen(Color.Black);
            //MessageBox.Show(""+this.positionX+" "+this.positionY+" "+this.size);

            g.DrawEllipse(myPen, this.positionX, this.positionY, this.size, this.size/2);

            pupil.paintPupil(g);
        }

        public void close()
        {
            this.pupil.setUnvisible();

        }

        public int getPositionX()
        {
            return this.positionX;
        }

        public int getPositionY()
        {
            return this.positionY;
        }

        public int getWidth()
        {

            return this.size;
        }

        public Pupil getPupil()
        {
            return this.pupil;
        }
    }
}
