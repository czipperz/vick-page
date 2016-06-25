/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef HEADER_GUARD_PAGE_H
#define HEADER_GUARD_PAGE_H

#include "contents.hh"

namespace vick {
namespace page {

/*!
 * \file page.hh
 *
 * \brief Defines functions for moving up and down using
 * `contents.max_y` as the size of the page.
 */

/*!
 * \brief Moves down half of `contents.max_y` and bounds checks.
 *
 * `contents.x` is unchanged.
 *
 * \post contents.y < contents.cont.size()
 */
boost::optional<std::shared_ptr<change> >
move_down_half_page(contents&, boost::optional<int> = 1);

/*!
 * \brief Moves up half of `contents.max_y` and bounds checks.
 *
 * `contents.x` is unchanged.
 *
 * \post contents.y >= 0
 */
boost::optional<std::shared_ptr<change> >
move_up_half_page(contents&, boost::optional<int> = 1);

/*!
 * \brief Moves down `contents.max_y` and bounds checks.
 *
 * `contents.x` is unchanged.
 *
 * \post contents.y < contents.cont.size()
 */
boost::optional<std::shared_ptr<change> >
move_down_page(contents&, boost::optional<int> = 1);

/*!
 * \brief Moves up `contents.max_y` and bounds checks.
 *
 * `contents.x` is unchanged.
 *
 * \post contents.y >= 0
 */
boost::optional<std::shared_ptr<change> >
move_up_page(contents&, boost::optional<int> = 1);

/*!
 * \brief Moves `contents.y_offset` such that it is equal to
 * `contents.y`.
 *
 * `contents.x` and `contents.y` is unchanged.
 *
 * \post `contents.y = contents.y_offset` (but `contents.y` is
 *       unchanged.)
 * \post `contents.y > 0`
 */
boost::optional<std::shared_ptr<change> >
recenter_top(contents&, boost::optional<int> = boost::none);

/*!
 * \brief Moves `contents.y_offset` such that `contents.y` is centered
 * between `contents.y_offset` and `contents.y_offset +
 * contents.max_y`.
 *
 * `contents.x` and `contents.y` is unchanged.
 *
 * \post `contents.y = contents.y_offset + contents.max_y / 2 - 1`
 *       (but `contents.y` is unchanged.)
 * \post `contents.y > 0`
 */
boost::optional<std::shared_ptr<change> >
recenter_middle(contents&, boost::optional<int> = boost::none);

/*!
 * \brief Moves `contents.y_offset` such that `contents.y` is equal to
 * `contents.y_offset + contents.max_y`.
 *
 * `contents.x` and `contents.y` is unchanged.
 *
 * \post `contents.y = contents.y_offset + contents.max_y - 2` (but
 *       `contents.y` is unchanged.)
 * \post `contents.y > 0`
 */
boost::optional<std::shared_ptr<change> >
recenter_bottom(contents&, boost::optional<int> = boost::none);

/*!
 * \brief Moves `contents.y` such that it is equal to
 * `contents.y_offset`
 *
 * `contents.x` and `contents.y_offset` is unchanged.
 *
 * \post `contents.y = contents.y_offset` (simple assignment.)
 */
boost::optional<std::shared_ptr<change> >
move_to_window_top(contents&, boost::optional<int> = boost::none);

/*!
 * \brief Moves `contents.y` such that it is centered between
 * `contents.y_offset` and `contents.y_offset + contents.max_y`
 *
 * `contents.x` and `contents.y_offset` is unchanged.
 *
 * \post `contents.y = contents.y_offset + contents.max_y / 2 - 1`
 *       (simple assignment.)
 */
boost::optional<std::shared_ptr<change> >
move_to_window_middle(contents&, boost::optional<int> = boost::none);

/*!
 * \brief Moves `contents.y` such that it is equal to
 * `contents.y_offset + contents.max_y - 2`
 *
 * `contents.x` and `contents.y_offset` is unchanged.
 *
 * \post `contents.y = contents.y_offset + contents.max_y` (simple
 *       assignment.)
 */
boost::optional<std::shared_ptr<change> >
move_to_window_bottom(contents&, boost::optional<int> = boost::none);
}
}

#endif
