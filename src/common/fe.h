#include "userlist.h"
#include "dcc.h"

#ifndef XCHAT_FE_H
#define XCHAT_FE_H

/* for storage of /menu entries */
typedef struct
{
	int pos;	/* position */
	short state;	/* state of toggle items */
	short markup;	/* use pango markup? */
	short enable;	/* enabled? sensitivity */
	short modifier;	/* keybinding */
	int key;
	char *path;
	char *label;
	char *cmd;
	char *ucmd;	/* unselect command (toggles) */
} menu_entry;

int fe_args (int argc, char *argv[]);
void fe_init (void);
void fe_main (void);
void fe_cleanup (void);
void fe_exit (void);
int fe_timeout_add (int interval, void *callback, void *userdata);
void fe_timeout_remove (int tag);
void fe_new_window (struct session *sess, int focus);
void fe_new_server (struct server *serv);
void fe_add_rawlog (struct server *serv, char *text, int len, int outbound);
#define FE_MSG_WAIT 1
#define FE_MSG_INFO 2
#define FE_MSG_WARN 4
#define FE_MSG_ERROR 8
#define FE_MSG_MARKUP 16
void fe_message (char *msg, int flags);
#define FIA_READ 1
#define FIA_WRITE 2
#define FIA_EX 4
#define FIA_FD 8
int fe_input_add (int sok, int flags, void *func, void *data);
void fe_input_remove (int tag);
void fe_idle_add (void *func, void *data);
void fe_set_topic (struct session *sess, char *topic);
void fe_set_hilight (struct session *sess);
void fe_set_tab_color (struct session *sess, int col);
void fe_flash_window (struct session *sess);
void fe_update_mode_buttons (struct session *sess, char mode, char sign);
void fe_update_channel_key (struct session *sess);
void fe_update_channel_limit (struct session *sess);
int fe_is_chanwindow (struct server *serv);
void fe_add_chan_list (struct server *serv, char *chan, char *users,
							  char *topic);
void fe_chan_list_end (struct server *serv);
int fe_is_banwindow (struct session *sess);
void fe_add_ban_list (struct session *sess, char *mask, char *who, char *when, int is_exemption);
void fe_ban_list_end (struct session *sess, int is_exemption);
void fe_notify_update (char *name);
void fe_text_clear (struct session *sess);
void fe_close_window (struct session *sess);
void fe_progressbar_start (struct session *sess);
void fe_progressbar_end (struct server *serv);
void fe_print_text (struct session *sess, char *text);
void fe_userlist_insert (struct session *sess, struct User *newuser, int row, int sel);
int fe_userlist_remove (struct session *sess, struct User *user);
void fe_userlist_rehash (struct session *sess, struct User *user);
void fe_userlist_move (struct session *sess, struct User *user, int new_row);
void fe_userlist_numbers (struct session *sess);
void fe_userlist_clear (struct session *sess);
void fe_userlist_set_selected (struct session *sess);
void fe_uselect (session *sess, char *word[], int do_clear, int scroll_to);
void fe_dcc_add (struct DCC *dcc);
void fe_dcc_update (struct DCC *dcc);
void fe_dcc_remove (struct DCC *dcc);
int fe_dcc_open_recv_win (int passive);
int fe_dcc_open_send_win (int passive);
int fe_dcc_open_chat_win (int passive);
void fe_clear_channel (struct session *sess);
void fe_session_callback (struct session *sess);
void fe_server_callback (struct server *serv);
void fe_url_add (const char *text);
void fe_pluginlist_update (void);
void fe_buttons_update (struct session *sess);
void fe_dlgbuttons_update (struct session *sess);
void fe_dcc_send_filereq (struct session *sess, char *nick, int maxcps, int passive);
void fe_set_channel (struct session *sess);
void fe_set_title (struct session *sess);
void fe_set_nonchannel (struct session *sess, int state);
void fe_set_nick (struct server *serv, char *newnick);
void fe_ignore_update (int level);
void fe_beep (void);
void fe_lastlog (session *sess, session *lastlog_sess, char *sstr, gboolean regexp);
void fe_set_lag (server *serv, int lag);
void fe_set_throttle (server *serv);
void fe_set_away (server *serv);
void fe_set_color_paste (session *sess, int status);
void fe_serverlist_open (session *sess);
void fe_get_str (char *prompt, char *def, void *callback, void *ud);
void fe_get_int (char *prompt, int def, void *callback, void *ud);
#define FRF_WRITE 1	/* save file */
#define FRF_MULTIPLE 2	/* multi-select */
#define FRF_ADDFOLDER 4	/* add ~/.xchat2 to favourites */
#define FRF_CHOOSEFOLDER 8	/* choosing a folder only */
#define FRF_FILTERISINITIAL 16	/* unused */
#define FRF_NOASKOVERWRITE 32	/* don't ask to overwrite existing files */
void fe_get_file (const char *title, char *initial,
				 void (*callback) (void *userdata, char *file), void *userdata,
				 int flags);
void fe_ctrl_gui (session *sess, int action, int arg);
int fe_gui_info (session *sess, int info_type);
void *fe_gui_info_ptr (session *sess, int info_type);
void fe_confirm (const char *message, void (*yesproc)(void *), void (*noproc)(void *), void *ud);
char *fe_get_inputbox_contents (struct session *sess);
int fe_get_inputbox_cursor (struct session *sess);
void fe_set_inputbox_contents (struct session *sess, char *text);
void fe_set_inputbox_cursor (struct session *sess, int delta, int pos);
void fe_open_url (const char *url);
void fe_menu_del (menu_entry *);
char *fe_menu_add (menu_entry *);
void fe_menu_update (menu_entry *);
#define FE_SE_CONNECT 0
#define FE_SE_LOGGEDIN 1
#define FE_SE_DISCONNECT 2
#define FE_SE_RECONDELAY 3
#define FE_SE_CONNECTING 4
void fe_server_event (server *serv, int type, int arg);
void fe_tray_message (void);
/* pass NULL filename2 for default xchat icon */
void fe_tray_set_flash (const char *filename1, const char *filename2, int timeout);
/* pass NULL filename for default xchat icon */
void fe_tray_set_icon (const char *filename);
void fe_tray_set_tooltip (const char *text);
void fe_tray_set_balloon (const char *title, const char *text);

#endif
