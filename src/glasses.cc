// Copyright (C) 2015 Chi-kwan Chan
// Copyright (C) 2015 Steward Observatory
//
// This file is part of insight.
//
// Insight is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Insight is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with insight.  If not, see <http://www.gnu.org/licenses/>.

#include "insight.h"

void glasses(unsigned img)
{
	float grey[] = {0.5f, 0.5f, 0.5f, 1.0f};

	glTranslatef(0.052f, 0.02f,-0.05);
	glScalef(0.01f, 0.01f, 0.01f);

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, grey);
	glBindTexture(GL_TEXTURE_2D, img);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
		glNormal3f( 0, 0, 1);
		glTexCoord2f(1, 0); glVertex3f( 1, 1, 0);
		glTexCoord2f(0, 0); glVertex3f(-1, 1, 0);
		glTexCoord2f(0, 1); glVertex3f(-1,-1, 0);
		glTexCoord2f(1, 1); glVertex3f( 1,-1, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
