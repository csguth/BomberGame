/*
 * VideoConfiguration.h
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#ifndef VIDEOCONFIGURATION_H_
#define VIDEOCONFIGURATION_H_

namespace bg {

class VideoConfiguration {
	static VideoConfiguration * m_instance;
	VideoConfiguration();
public:
	virtual ~VideoConfiguration();
	static VideoConfiguration* instance();

	const int cellSizeInPixels() const { return 16; }
	const int numCells() const { return 16; }
	const float worldToScreenScaleFactor() const { return 16.f; }
};

} /* namespace bg */

#endif /* VIDEOCONFIGURATION_H_ */
