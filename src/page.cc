#include "page.hh"

namespace vick {
namespace page {

boost::optional<std::shared_ptr<change> >
move_down_half_page(contents& contents, boost::optional<int> opt)
{
    if (opt) {
        if (*opt == 0)
            return boost::none;
        if (*opt < 0)
            return move_up_half_page(contents, -*opt);
    }
    for (int num = opt ? *opt : 1; num > 0; --num) {
        if (contents.y + contents.max_y / 2 >= contents.cont.size()) {
            contents.y = contents.cont.size() - 1;
            return boost::none;
        } else {
            contents.y += contents.max_y / 2;
        }
    }
    return boost::none;
}

boost::optional<std::shared_ptr<change> >
move_up_half_page(contents& contents, boost::optional<int> opt)
{
    if (opt) {
        if (*opt == 0)
            return boost::none;
        if (*opt < 0)
            return move_down_half_page(contents, -*opt);
    }
    for (int num = opt ? *opt : 1; num > 0; --num) {
        if (contents.y < contents.max_y / 2) {
            contents.y = 0;
            return boost::none;
        } else {
            contents.y -= contents.max_y / 2;
        }
    }
    return boost::none;
}

boost::optional<std::shared_ptr<change> >
move_down_page(contents& contents, boost::optional<int> opt)
{
    if (opt) {
        if (*opt == 0)
            return boost::none;
        if (*opt < 0)
            return move_up_page(contents, -*opt);
    }
    for (int num = opt ? *opt : 1; num > 0; --num) {
        if (contents.y + contents.max_y >= contents.cont.size()) {
            contents.y = contents.cont.size() - 1;
            return boost::none;
        } else {
            contents.y += contents.max_y;
        }
    }
    return boost::none;
}

boost::optional<std::shared_ptr<change> >
move_up_page(contents& contents, boost::optional<int> opt)
{
    if (opt) {
        if (*opt == 0)
            return boost::none;
        if (*opt < 0)
            return move_down_page(contents, -*opt);
    }
    for (int num = opt ? *opt : 1; num > 0; --num) {
        if (contents.y < contents.max_y) {
            contents.y = 0;
            return boost::none;
        } else {
            contents.y -= contents.max_y;
        }
    }
    return boost::none;
}

boost::optional<std::shared_ptr<change> >
recenter_top(contents& contents, boost::optional<int>) {
    contents.y_offset = contents.y;
    return boost::none;
}

boost::optional<std::shared_ptr<change> >
recenter_middle(contents& contents, boost::optional<int>) {
    if (contents.y < contents.max_y / 2 - 1) contents.y_offset = 0;
    else contents.y_offset = contents.y - contents.max_y / 2 + 1;
    return boost::none;
}

boost::optional<std::shared_ptr<change> >
recenter_bottom(contents& contents, boost::optional<int>) {
    if (contents.y < contents.max_y - 2) contents.y_offset = 0;
    else contents.y_offset = contents.y - contents.max_y + 2;
    return boost::none;
}

boost::optional<std::shared_ptr<change> >
move_to_window_top(contents& contents, boost::optional<int>) {
    contents.y = contents.y_offset;
    return boost::none;
}

boost::optional<std::shared_ptr<change> >
move_to_window_middle(contents& contents, boost::optional<int>) {
    contents.y = contents.y_offset + contents.max_y / 2 - 1;
    return boost::none;
}

boost::optional<std::shared_ptr<change> >
move_to_window_bottom(contents& contents, boost::optional<int>) {
    contents.y = contents.y_offset + contents.max_y - 2;
    return boost::none;
}

}
}
