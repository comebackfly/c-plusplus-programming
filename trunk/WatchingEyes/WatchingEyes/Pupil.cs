using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace WatchingEyes
{
    class Pupil
    {
        private int positionX;
        private int positionY;
        private int size;
        private Graphics g;
        private SolidBrush pupilBrush;

        public Pupil()
        {
            pupilBrush = new SolidBrush(Color.LawnGreen);
        }

        public void setPupil(int positionX, int positionY, int size)
        {
            this.positionX = positionX;
            this.positionY = positionY;
            this.size=size;
        }

        public void paintPupil(Graphics g){
            this.g = g;
            // Create a new pen that we shall use for drawing the line
            
            //MessageBox.Show(""+this.positionX+" "+this.positionY+" "+this.size);
            if (this.positionX != 0)
            {
                g.FillEllipse(pupilBrush, this.positionX, this.positionY, this.size, this.size);
            }
        }

        public void updatePupil(int positionX, int positionY)
        {
            if (positionX == 0 || positionY == 0)
            {
                g.FillEllipse(pupilBrush, this.positionX, this.positionY, this.size, this.size);
            }
            else
            {
                g.FillEllipse(pupilBrush, positionX, positionY, this.size, this.size);
            }
          
        }

        public void setUnvisible()
        {
            SolidBrush invisible = new SolidBrush(Color.Teal);
            g.FillEllipse(invisible, this.positionX, this.positionY, this.size, this.size);
        }
    }
}
