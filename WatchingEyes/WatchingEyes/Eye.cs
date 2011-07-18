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
        private Pupil pupil;
        private Graphics g;
        private Boolean closed;

        public Eye(int positionX, int positionY, int size)
        {
            this.positionX = positionX;
            this.positionY = positionY;
            this.size = size;
        }

        public void paintEye(Graphics g, int clientWidth, int clientHeight)
        {
            // Create a new pen that we shall use for drawing the line
            Pen blackPen = new Pen(Color.Black);
            this.positionX = clientWidth;
            this.positionY = clientHeight;

            g.DrawEllipse(blackPen, clientWidth, clientHeight, this.size, this.size / 2);
            blackPen.Dispose();

            // this.pupil.paintPupil(g, clientWidth+12, clientHeight+7);
        }

        public void updatePupil(Graphics g, float positionX, float positionY, Boolean pupilClosed)
        {
            this.pupil.updatePupil(g, positionX, positionY, pupilClosed);
        }

        public void close(Graphics g)
        {
            SolidBrush invisible = new SolidBrush(Color.Black);
            g.FillEllipse(invisible, this.positionX, this.positionY, this.size, this.size / 2);
            this.pupil.setUnvisible(g);
            invisible.Dispose();
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

        public void setPupil(Pupil pupil)
        {
            this.pupil = pupil;
        }

        public Boolean isClosed()
        {
            return this.closed;
        }

        public void setClosed(Boolean value)
        {
            this.closed = value;
        }

        public Point getCenter()
        {
            Point centerPoint = new Point();

            centerPoint.X = this.positionX + this.size / 2;
            centerPoint.Y = this.positionY + this.size / 4;

            return centerPoint;
        }
    }
}