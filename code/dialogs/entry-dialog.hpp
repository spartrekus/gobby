/* Gobby - GTK-based collaborative text editor
 * Copyright (C) 2008-2014 Armin Burgmeier <armin@arbur.net>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _GOBBY_ENTRYDIALOG_HPP_
#define _GOBBY_ENTRYDIALOG_HPP_

#include <gtkmm/dialog.h>
#include <gtkmm/label.h>
#include <gtkmm/entry.h>
#include <gtkmm/builder.h>

namespace Gobby
{

class EntryDialog: public Gtk::Dialog
{
private:
	friend class Gtk::Builder;

	EntryDialog(GtkDialog* cobject,
	            const Glib::RefPtr<Gtk::Builder>& builder);

public:
	static std::unique_ptr<EntryDialog> create(
		Gtk::Window& parent, const Glib::ustring& title,
		const Glib::ustring& intro_text);

	Glib::ustring get_text() const;
	void set_text(const Glib::ustring& text);

protected:
	virtual void on_show();

	Gtk::Label* m_intro_label;
	Gtk::Entry* m_entry;
};

}

#endif // _GOBBY_ENTRYDIALOG_HPP_

