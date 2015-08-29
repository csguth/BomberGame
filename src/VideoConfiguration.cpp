/*
 * VideoConfiguration.cpp
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#include "VideoConfiguration.h"

namespace bg {

VideoConfiguration* VideoConfiguration::m_instance(nullptr);

VideoConfiguration::VideoConfiguration() {
}

VideoConfiguration::~VideoConfiguration() {
}

VideoConfiguration* VideoConfiguration::instance() {
	if(!m_instance)
		m_instance = new VideoConfiguration;
	return m_instance;
}

} /* namespace bg */
