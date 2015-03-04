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
#include "vol.h"
#include <cstdio>
#include <cstdint>

unsigned mkvol(const char *name)
{
	unsigned vol;
	glGenTextures(1, &vol);
	glBindTexture(GL_TEXTURE_3D, vol);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        uint8_t *data = (uint8_t *)malloc(128 * 128 * 128 * 4);
        for(int i = 0; i < 128; ++i)
	        for(int j = 0; j < 128; ++j)
		        for(int k = 0; k < 128; ++k) {
			        int   h = ((i * 128 + j) * 128 + k) * 4;
			        float g = exp(-((i-63.5) * (i-63.5) / 4096 +
			                        (j-63.5) * (j-63.5) / 2048 +
			                        (k-63.5) * (k-63.5) / 1024));
			        data[h+0] = 255 * g;
			        data[h+1] = 255 * g;
			        data[h+2] = 255 * g;
			        data[h+3] =  63 * g;
		        }

        glTexImage3D(GL_TEXTURE_3D, 0, GL_RGBA,
                     128, 128, 128, 0,
                     GL_RGBA, GL_UNSIGNED_BYTE, data);

        free(data);

        return vol;
}

void rmvol(unsigned vol)
{
	glDeleteTextures(1, &vol);
}
