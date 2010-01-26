/*****************************************************************************
 * video.hpp: video part of an media player
 *****************************************************************************
 * Copyright (C) 2010 the VideoLAN team
 * $Id$
 *
 * Authors: Rémi Duraffort <ivoire@videolan.org>
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#ifndef LIBVLCPP_VIDEO_HPP
#define LIBVLCPP_VIDEO_HPP

#include <vlc/libvlc.h>
#include <vlc/libvlc_media.h>
#include <vlc/libvlc_media_player.h>

#include "libvlc.hpp"

namespace libvlc
{

class Video
{
public:
    /**
     * Constructor
     * @param player: the player handling the video
     */
    Video( libvlc_media_player_t *player );

    /** Destructor */
    ~Video();

    /**
     * Get the height of the video
     * @return the height of the video
     */
    int height();

    /**
     * Get the width of the video
     * @return the widht of the video
     */
    int width();

    /**
     * Get the current scaling factor of the video
     * @return the current scaling factor or 0 if the video is set to fit to the output
     */
    float scale();

    /**
     * Set the scaling factor
     * @param factor: the new scaling factor
     */
    void setScale( float factor );

    /**
     * Get the current video aspect ratio
     * @return the aspect ratio
     */
    char *aspectRatio();

    /**
     * set the video aspect ratio
     * @param aspect_ratio: the aspect ratio
     */
    void setAspectRatio( const char *aspect_ratio );

    /**
     * Get the current video subtitle
     * @return the video subtitle
     */
    int spu();

    /**
     * Get the number of available video subtitles
     * @return the number of subtitle
     */
    int spuCount();

    /**
     * Set the video subtitle index
     * @param spu: the video subtitle
     */
    void setSpu( int spu );

    /** Get informations about the current spu */

    /**
     * Set the subtitle file
     * @param subtitle_file: the new subtitle file
     */
    void setSubtitleFile( const char *subtitle_file );

    /** Get title description */

    /** Get chapter description */

    /**
     * Get the current crop filter geometry
     * @return the crop geonmetry
     */
    char *cropGeometry();

    /**
     * Set the crop geometry
     * @param geometry: the new crop filter geometry
     */
    void setCropGeometry( const char *geometry );

    /**
     * Get the current video track
     * @return the video track
     */
    int track();

    /**
     * Get the number of video tracks
     * @return the number of video tracks
     */
    int trackCount();

    /**
     * Set the video track
     * @param track: the video track
     */
    void setTrack( int track );

    /** get track description */

    /**
     * Take a snapshot and save it to a file
     * @param filepath: path where to save the file
     * @param widht: widht of the snapshot
     * @param height: height of the snapshot
     */
    void snapshot( const char *filepath, int widht, int height );

    /**
     * Enable or disable deinterlace filter and select the deinterlace filter to use
     * @param enable: true to enable the deinterlace filter
     * @param mode: the deinterlace filter to use
     */
    void deinterlace( int enable, const char *mode );

private:
    /** The media player instance of libvlc */
    libvlc_media_player_t *m_player;
};

};

#endif // LIBVLCPP_VIDEO_HPP

