/***************************************************************************
 *   Copyright (C) 2008 by Oleg Khudyakov   *
 *   prcoder@gmail.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "fht.h"
#include <math.h>

FHT::FHT()
{
}


FHT::~FHT()
{
}

/*!
    \fn FHT::transform(double *buf, int n, int skip)
 */
void FHT::transform(double *buf, int n, int skip)
{
    reverse(buf, n, skip);
    scale(buf, n, skip);
}


/*!
    \fn FHT::reverse(double buf, int n, int skip)
 */
void FHT::reverse(double *buf, int n, int skip)
{
    int i, j, k, k1, k4, kx, l;
    double *p1, *p2, *p3;
    double wpr, wpi;

    for (k=0; (1<<k)<n; k++);
    k &= 1;
    n *= skip;
    for (i=skip,j=0; i<n; i+=skip)
    {
        for (l=n>>1; (!((j^=l)&l)); l>>=1);
        if (i>j)
        {
            double x0=buf[i];
            buf[i]=buf[j];
            buf[j]=x0;
        }
    }
    k1 = skip << k;
    k4 = k1 << 2;
    kx = k1 >> 1;
    p1 = buf + k1;
    p2 = p1 + k1;
    p3 = p2 + k1;
    if (k==0)
    {
        for (i=0;i<n;i+=k4)
        {
            double x0, x1, x2, x3;
            x1 = buf[i] - p1[i];
            x0 = buf[i] + p1[i];
            x3 = p2[i] - p3[i];
            x2 = p2[i] + p3[i];
            p2[i] = x0 - x2;
            buf[i] = x0 + x2;
            p3[i] = x1 - x3;
            p1[i] = x1 + x3;
        }
    }
    else
    {
        for (i=0,j=kx;i<n;i+=k4,j+=k4)
        {
            double x0, x1, x2, x3, x4, x5;
            x0 = buf[i] - buf[j];
            x1 = buf[i] + buf[j];
            x2 = p1[i] - p1[j];
            x3 = p1[i] + p1[j];
            x4 = x1 - x3;
            x1 += x3;
            x3 = x0 - x2;
            x0 += x2;
            x5 = p2[i] + p2[j];
            x2 = p2[i] - p2[j];
            x2 *= M_SQRT2;
            p2[j] = x0 - x2;
            buf[j] = x0 + x2;
            x2 = p3[i] + p3[j];
            x0 = p3[i] - p3[j];
            x0 *= M_SQRT2;
            p3[j] = x3 - x0;
            p1[j] = x3 + x0;
            x0 = x5 - x2;
            x5 += x2;
            p2[i] = x1 - x5;
            buf[i] = x1 + x5;
            p3[i] = x4 - x0;
            p1[i] = x4 + x0;
        }
    }
    while (k4<n)
    {
        double s1, c1;
        k += 2;
        k1 = skip << k;
        k4 = k1 << 2;
        kx = k1 >> 1;
        p1 = buf + k1;
        p2 = p1 + k1;
        p3 = p2 + k1;
        for(i=0, j=kx; i<n; i+=k4, j+=k4)
        {
            double x0, x1, x2, x3;
            x1 = buf[i] - p1[i];
            x0 = buf[i] + p1[i];
            x3 = p2[i] - p3[i];
            x2 = p2[i] + p3[i];
            p2[i] = x0 - x2;
            buf[i] = x0 + x2;
            p3[i] = x1 - x3;
            p1[i] = x1 + x3;
            x1 = buf[j] - p1[j];
            x0 = buf[j] + p1[j];
            x3 = M_SQRT2 * p3[j];
            x2 = M_SQRT2 * p2[j];
            p2[j] = x0 - x2;
            buf[j] = x0 + x2;
            p3[j] = x1 - x3;
            p1[j] = x1 + x3;
        }

        wpr = -2.0*sintab[k+1]*sintab[k+1];
        wpi = sintab[k];
        c1 = 1;
        s1 = 0;

        for (l=skip; l<kx; l+=skip)
        {
            double c2, s2, c3, s3, t;
            c1 += (t=c1)*wpr - s1*wpi;
            s1 += s1*wpr + t*wpi;

            c2 = c1*c1 - s1*s1;
            s2 = 2*(c1*s1);
            c3 = c2*c1 - s2*s1;
            s3 = c2*s1 + s2*c1;

            for (i=l, j=k1-l; i<n; i+=k4, j+=k4)
            {
                double x0, x1, x2, x3, x4, x5, x6;
                x0 = p1[i]*c2 + p1[j]*s2;
                x1 = p1[i]*s2 - p1[j]*c2;
                x2 = p2[i]*c1 + p2[j]*s1;
                x3 = p2[i]*s1 - p2[j]*c1;
                x4 = p3[i]*c3 + p3[j]*s3;
                x5 = p3[i]*s3 - p3[j]*c3;
                x6 = x2 - x4;
                x4 += x2;
                x2 = x3 - x5;
                x5 += x3;
                x3 = buf[i]- x0;
                p3[i] = x3 + x2;
                p1[i] = x3 - x2;
                x3 = buf[i] + x0;
                p2[i] = x3 - x4;
                buf[i] = x3 + x4;
                x3 = buf[j] - x1;
                p3[j] = x3 - x5;
                p1[j] = x3 + x5;
                x3 = buf[j] + x1;
                p2[j] = x3 - x6;
                buf[j] = x3 + x6;
            }
        }
    }
}

/*!
    \fn FHT::scale(double *buf, int n, int skip)
 */
void FHT::scale(double *buf, int n, int skip)
{
    for (int i=0; i<n; i+=skip)
    {
        buf[i] /= n;
    }
}

const double FHT::sintab[22]=
{
    1.0000000000000000000000000000000000000000000000000,
    .70710678118654752440084436210484903928483593768846,
    .38268343236508977172845998403039886676134456248561,
    .19509032201612826784828486847702224092769161775195,
    .09801714032956060199419556388864184586113667316749,
    .04906767432741801425495497694268265831474536302574,
    .02454122852291228803173452945928292506546611923944,
    .01227153828571992607940826195100321214037231959176,
    .00613588464915447535964023459037258091705788631738,
    .00306795676296597627014536549091984251894461021344,
    .00153398018628476561230369715026407907995486457522,
    .00076699031874270452693856835794857664314091945205,
    .00038349518757139558907246168118138126339502603495,
    .00019174759731070330743990956198900093346887403385,
    .00009587379909597734587051721097647635118706561284,
    .00004793689960306688454900399049465887274686668768,
    .00002396844980841821872918657716502182009476147489,
    .00001198422490506970642152156159698898480473197753
};
