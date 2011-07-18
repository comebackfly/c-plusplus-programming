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
        private float positionX;
        private float positionY;
        private int size;

        public Pupil(int positionX, int positionY, int size)
        {
            this.size = size;
            this.positionX = positionX;
            this.positionY = positionY;
            
        }

        public void paintPupil(Graphics g, int clientWidth, int clientHeight)
        {
            // Create a new pen that we shall use for drawing the line
            SolidBrush pupilBrush = new SolidBrush(Color.Blue);
            g.FillEllipse(pupilBrush, clientWidth, clientHeight, this.size, this.size);
            pupilBrush.Dispose();
        }

        public void updatePupil(Graphics g, float positionX, float positionY, Boolean isVisible)
        {
            if (isVisible)
            {
                SolidBrush pupilBrush = new SolidBrush(Color.Blue);
                this.positionX = positionX;
                this.positionY = positionY;
                g.FillEllipse(pupilBrush, positionX, positionY, this.size, this.size);
                pupilBrush.Dispose();
            }
        }

        public void setUnvisible(Graphics g)
        {
            SolidBrush invisible = new SolidBrush(Color.Black);
            g.FillEllipse(invisible, this.positionX, this.positionY, 0, 0);
            invisible.Dispose();

        }

        public float getPositionX()
        {
            return this.positionX;
        }

        public float getPositionY()
        {
            return this.positionY;
        }
    }
}
