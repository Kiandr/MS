using GenericRepository.Models;
using GenericRepository.Repository.Implementation;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;

namespace GenericRepository.Controllers
{
    public class testController : Controller
    {
        private ImplementationProjectTest repo = new ImplementationProjectTest();

        // GET: test
        public ActionResult Index()
        {
            var data = repo.GetAll();

            return View("~/Views/test/testView.cshtml",data);
        }

        // GET: test/Details/5
        public ActionResult Details(int id)
        {
            return View();
        }

        // GET: test/Create
        [HttpPost]
        public ActionResult Add(testModel model)
        {
            repo.Creat(model);
            return new HttpStatusCodeResult(HttpStatusCode.OK);
        }

        // POST: test/Create
        [HttpPost]
        public ActionResult Create(FormCollection collection)
        {
            try
            {
                // TODO: Add insert logic here

                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }

        // GET: test/Edit/5
        public ActionResult Edit(int id)
        {
            return View();
        }

        // POST: test/Edit/5
        [HttpPost]
        public ActionResult Edit(int id, FormCollection collection)
        {
            try
            {
                // TODO: Add update logic here

                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }

        // GET: test/Delete/5
        public ActionResult Delete(int id)
        {
            return View();
        }

        // POST: test/Delete/5
        [HttpPost]
        public ActionResult Delete(int id, FormCollection collection)
        {
            try
            {
                // TODO: Add delete logic here

                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }
    }
}
