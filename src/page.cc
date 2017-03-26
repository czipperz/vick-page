/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "../lib.hh"

namespace vick {
namespace page {

std::shared_ptr<change>
move_down_half_page(contents& contents, boost::optional<int> opt) {
    if (opt) {
        if (*opt == 0)
            return nullptr;
        if (*opt < 0)
            return move_up_half_page(contents, -*opt);
    }
    for (int num = opt ? *opt : 1; num > 0; --num) {
        if (contents.y + contents.max_y / 2 >= contents.cont.size()) {
            contents.y = contents.cont.size() - 1;
            return nullptr;
        } else {
            contents.y += contents.max_y / 2;
        }
    }
    return nullptr;
}

std::shared_ptr<change>
move_up_half_page(contents& contents, boost::optional<int> opt) {
    if (opt) {
        if (*opt == 0)
            return nullptr;
        if (*opt < 0)
            return move_down_half_page(contents, -*opt);
    }
    for (int num = opt ? *opt : 1; num > 0; --num) {
        if (contents.y < contents.max_y / 2) {
            contents.y = 0;
            return nullptr;
        } else {
            contents.y -= contents.max_y / 2;
        }
    }
    return nullptr;
}

std::shared_ptr<change>
move_down_page(contents& contents, boost::optional<int> opt) {
    if (opt) {
        if (*opt == 0)
            return nullptr;
        if (*opt < 0)
            return move_up_page(contents, -*opt);
    }
    for (int num = opt ? *opt : 1; num > 0; --num) {
        if (contents.y + contents.max_y >= contents.cont.size()) {
            contents.y = contents.cont.size() - 1;
            return nullptr;
        } else {
            contents.y += contents.max_y;
        }
    }
    return nullptr;
}

std::shared_ptr<change>
move_up_page(contents& contents, boost::optional<int> opt) {
    if (opt) {
        if (*opt == 0)
            return nullptr;
        if (*opt < 0)
            return move_down_page(contents, -*opt);
    }
    for (int num = opt ? *opt : 1; num > 0; --num) {
        if (contents.y < contents.max_y) {
            contents.y = 0;
            return nullptr;
        } else {
            contents.y -= contents.max_y;
        }
    }
    return nullptr;
}

std::shared_ptr<change>
recenter_top(contents& contents, boost::optional<int>) {
    contents.y_offset = contents.y;
    return nullptr;
}

std::shared_ptr<change>
recenter_middle(contents& contents, boost::optional<int>) {
    if (contents.y < contents.max_y / 2 - 1)
        contents.y_offset = 0;
    else
        contents.y_offset = contents.y - contents.max_y / 2 + 1;
    return nullptr;
}

std::shared_ptr<change>
recenter_bottom(contents& contents, boost::optional<int>) {
    if (contents.y < contents.max_y - 2)
        contents.y_offset = 0;
    else
        contents.y_offset = contents.y - contents.max_y + 2;
    return nullptr;
}

std::shared_ptr<change>
move_to_window_top(contents& contents, boost::optional<int>) {
    contents.y = contents.y_offset;
    return nullptr;
}

std::shared_ptr<change>
move_to_window_middle(contents& contents, boost::optional<int>) {
    contents.y = contents.y_offset + contents.max_y / 2 - 1;
    return nullptr;
}

std::shared_ptr<change>
move_to_window_bottom(contents& contents, boost::optional<int>) {
    contents.y = contents.y_offset + contents.max_y - 2;
    return nullptr;
}
}
}
