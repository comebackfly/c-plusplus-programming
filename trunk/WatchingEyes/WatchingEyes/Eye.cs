﻿using System;
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

        public Eye(int positionX, int positionY, int size)
        {
            this.positionX = positionX;
            this.positionY = positionY;
            this.size=size;
        }

        public void paintEye(Graphics g, int clientWidth, int clientHeight)
        {
            this.g = g;
            // Create a new pen that we shall use for drawing the line
            Pen blackPen = new Pen(Color.Black);
            this.positionX = clientWidth;
            this.positionY = clientHeight;

            g.DrawEllipse(blackPen, clientWidth, clientHeight, this.size, this.size / 2);
            blackPen.Dispose();

            pupil.paintPupil(g, clientWidth+12, clientHeight+7);
        }

        public void updatePupil(Graphics g, int clientWidth, int clientHeight)
        {
            this.pupil.updatePupil(this.g, clientWidth, clientHeight);
        }

        public void close()
        {
            //MessageBox.Show("" + this.positionX + " " + this.positionY + " " + this.size);
            this.pupil.setUnvisible();
            SolidBrush invisible = new SolidBrush(Color.Black);
            //this.g.FillEllipse(invisible, this.positionX, this.positionY, this.size, this.size/2);
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
    }
}