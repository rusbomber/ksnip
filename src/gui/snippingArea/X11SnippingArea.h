/*
 * Copyright (C) 2018 Damir Porobic <damir.porobic@gmx.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef KSNIP_X11SNIPPINGAREA_H
#define KSNIP_X11SNIPPINGAREA_H

#include "AbstractSnippingArea.h"
#include "src/common/platform/HdpiScaler.h"

class X11SnippingArea : public AbstractSnippingArea
{
public:
	explicit X11SnippingArea(const QSharedPointer<IConfig> &config);
	~X11SnippingArea() override = default;
    QRect selectedRectArea() const override;

protected:
	void setFullScreen() override;
	QRectF getSnippingAreaGeometry() const override;

private:
	QRectF mDesktopGeometry;
	QPointF mOffset;
	HdpiScaler mHdpiScaler;
    QSharedPointer<IConfig> mConfig;

	void calculateDesktopGeometry();

private slots:
    void updateOffset();
};

#endif //KSNIP_X11SNIPPINGAREA_H
