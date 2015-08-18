USE test;
--
-- Table structure for table mlsn87_users
--

drop table if exists mlsn87_users;
create table mlsn87_users (
  customer_id   integer unsigned not null auto_increment,
  username      varchar(255) collate latin1_bin not null,
  password      varchar(255) collate latin1_bin not null,
  first         varchar(255),
  last          varchar(255),
  address       varchar(255),
  zip           varchar(10),
  phone         varchar(100),
  cc            varchar(17),
  cc_type       varchar(8),
  primary key (customer_id),
  unique key username (username)
);

insert into mlsn87_users values ('0', 'mlsn87', 'Junk123', 'Mike', 'Stotts', '9555 Jones Creek Rd',
        '63023', '314-555-9999', '0000 0000 0000 0000', 'visa');

--
-- Table structure for table mlsn87_products
--

drop table if exists mlsn87_products;

create table mlsn87_products (
  id            varchar(10),
  description   varchar(50),
  price         decimal(10,2)
);

insert into mlsn87_products values ('vanilla', 'French Vanilla', '3.49');
insert into mlsn87_products values ('hazelnut', 'Hazelnut Cream', '3.95');
insert into mlsn87_products values ('colombian', 'Colombian', '4.95');

--
-- Table structure for table mlsn87_orders
--

drop table if exists mlsn87_orders;
create table mlsn87_orders (
  invoice       integer unsigned not null auto_increment,
  date          date default null,
  customer_id   integer default null references mlsn87_users(customer_id),
  total         decimal(10,2),
  primary key (invoice)
); 

--
-- Table structure for table mlsn87_order_items
--

drop table if exists mlsn87_order_items;
create table mlsn87_order_items (
  id            integer unsigned not null auto_increment,
  invoice       integer unsigned not null references mlsn87_orders(invoice),
  product       varchar(10) not null references mlsn87_products(id),
  quantity      integer unsigned not null,
  primary key(id)
);
